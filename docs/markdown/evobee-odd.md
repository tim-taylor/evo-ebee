# EvoBee high level description

[[ [Return to top-level documentation menu](../../README.md) ]]

## Introduction

This document provides a high-level description of the EvoBee agent based simulation platform. It follows the *ODD* protocol (Overview, Design concepts, and Details) proposed by Grimm et al.[^Grimm2010] as a standardised format for the description of agent-based models.

[^Grimm2010]: http://dx.doi.org/10.1016/j.ecolmodel.2010.08.019 "The ODD protocol: A review and first update"

## Purpose

EvoBee is a spatially-explicit agent-based model designed to simulate interactions between pollinators and plant species under a variety of scenarios. It simulates a population of individual pollinators foraging an area containing one or more different plant species over the course of a season, and also changes and evolution in the plant population over the course of multiple seasons. 

## Entities, state variables, and scales

### Pollinator agents

Each  pollinator has a unique identification number. It keeps a record of its current position in the environment (a two-dimensional floating-point vector) and its current heading (a floating-point angle [0, 2π]). It has a pollen store, in which is recorded any pollen carried  after collection from visited flowers. It keeps a list of the id. numbers of the five most recently visited flowers, and at any given time it will not revisit a flower that is currently on this list. Finally, each pollinator has a foraging strategy, which is either *Forage Nearest* flower, or *Forage Any* flower. These strategies are explained in the [Process Overview](#process-overview-and-scheduling) section.

### Flower/Plant agents

In our model, each plant has a single flower, so we treat a plant and its flower as a single entity. Each flower has a unique identification number. It also has a species identification number, to signify which of the two species it belongs to. The flower keeps a record of its fixed position in the environment (a two-dimensional floating-point vector). It also keeps a record of the number of collectable pollen grains currently available in its anthers—this is initialised with a fixed number when a flower is created, and depleted when a pollinator visits the flower, when a fixed number of anther pollen grains are transferred to the pollinator’s pollen store. The flower has a stigma pollen store, recording any pollen that visiting pollinators have deposited (these may be conspecific or heterospecific grains). The only difference between flower  species is the pollen type produced and required for pollination.

### Pollen agents

Each pollen grain is modelled individually, and records the individual flower that produced it, its species type, and (when travelling in a pollinator’s pollen store), the number of flowers the pollinator has visited since the grain was originally collected. Pollen cannot move independently, it must be transferred between flower agents by pollinator agents and is at any time always on a flower anther, stigma, or on the body of a pollinator.

### Spatial Units

Simulation distances are measured in perceptual distance units (pdu). We define 1 pdu to correspond to the distance over which bumblebees can detect a plant’s flowers, ~0.7m [REF Dyer, Sparthe et al, 2008; Wertlen, Niggebrugge et al 2008].

In these experiments the environment is homogeneous (with the exception of the refuge areas described in the following section), so there are no state variables associated with particular positions within the environment.

### Environment

In most experiments, we study a continuous-space environment 200 x 200 pdu (140 x 140 m). We model a single species of insect pollinator and two species of flowering plant (labelled X and Y). A column of area 40 x 200 pdu on the “left” edge of the environment acts as a refuge for plant species X; only plants of this species can grow here. If during the reproduction phase a seed from species Y lands in the refuge of species X it is removed from the simulation. An equivalent column on the right edge of the environment acts as a refuge for species Y. Plants of either species can occupy the central remaining 120 x 200 pdu region. Following Waser’s approach, we have incorporated these refuges to promote the possibility of the stable coexistence of two plant species (see Waser’s experiment (4), Effects of Refugia). In Waser’s experiments, these refuges  lead to a slight increase in the mean duration for which the environment supported the coexistence of the two species before one went to fixation.

## Process overview and scheduling
    

### Overview of dynamics: foraging and reproduction phases
    

Our model features a 2D continuous spatial environment containing a population of flowering plants of two different species. Each plant has a single flower that can be foraged by members of a single population of insect pollinator agents. The simulation cycles through two phases, an insect  foraging and pollination phase, and a plant reproduction phase.

During the foraging and pollination phase, the pollinators forage from the fixed population of flowers, transferring pollen between flowers as they visit and, potentially, pollinating them. This  phase proceeds in discrete steps and ends after a specified number have elapsed. At this point, the plant reproduction phase begins.

During the plant reproduction phase, viable seeds from pollinated plants form the gene pool for a new generation of plants. All plants and pollinators from the previous generation are removed from the environment, and new plants are created based upon parents picked at random (without replacement) from the gene pool. New plants are distributed to random positions in the environment. New plants are created until all members of the gene pool have been reproduced, or until the maximum carrying capacity of the environment is reached. A new population of pollinators is then created and distributed to random starting positions in the environment. Next, a new foraging phase commences. This simulation continues to cycle until a specified number of foraging/reproduction phases have been completed.

### Pollinator dynamics

Each foraging phase begins with a population of 400 pollinators distributed uniform-randomly across the environment. Each pollinator collects a supply of pollen by visiting flowers. At each time step during the foraging phase, the order in which pollinators are selected is randomised. Each pollinator executes a new iteration of its foraging behaviour in each simulation time step. We studied two different pollinator foraging strategies in these experiments: *Forage Nearest* flower, and a variant,  *Forage Any* flower. In both strategies, every pollinator maintains a list of its five most recently visited individual flowers, and it will not revisit a flower that currently appears on this list. The differences between the strategies are as follows.

A pollinator following the *Forage Nearest* flower strategy  (Fig. 1a) will move to (and land upon) the nearest flower within a search radius of 1 pdu from its current position and that does not appear on its recently visited flower  list. If no flower meets these criteria, the pollinator moves a distance of 1 pdu in a uniform-randomly chosen direction. This is not a strategy real insects use,  but since in this work we are only interested in the relative success of flowering plants, as long as we are consistent in our approach across all simulations and we maintain our aspatial / well-mixed plant population, this simple model has been shown to be sufficient  [REF Zoe's ECAL paper].

A pollinator following the *Forage Any* flower strategy picks a flower to visit at random from all flowers in the entire environment, excluding those on its list of recently visited flowers. This strategy was introduced in addition to *Forage Nearest* flower as a mechanism to assess the potential impact of spatial and stochastic components of our simulation. The central region of the foraging environment is, as noted above, populated by either flower species. This is bordered on two opposite sides by refuges set aside for each flower species. A pollinator in the central region would be expected, in a well-mixed plant distribution  such as that we implement, to encounter a flower of one or the other plant species according to the probability specified by their current relative population sizes; i.e. in a 70:30 population distribution of the two plants, the pollinator expects with 70% to meet a flower of species X and 30% species Y. However, a pollinator within, or near, a refuge would not be expected to encounter flowers with a probability that matches this ratio. Their location and the spatial configuration of the environment would interfere with this. By comparing results generated by *Forage Nearest* flower to *Forage Any* flower, we can assess the impact of this on our experiments.

A second spatial aspect of the simulation is the floral density. Even though we eliminate floral patchiness in the central environmental foraging area by enforcing a well-mixed planting regime, flower density is only 0.4 flowers per (1 pdu2) cell. Consequently, a pollinator  will often see no flowers at all from its current location and will resort to a random walk as just noted above. The *Forage Any* flower  removes this floral density component from consideration by ensuring that the insect can fly directly to any flower in the environment immediately, whether or not it is within visual range. This extreme aspatial behaviour effectively collapses the environment to a single point from the perspective of the insect, and enables us to compare  standard spatial restrictions on movement to a completely aspatial baseline simulation.

Pollen transfer processes occur during  each flower visit by a pollinator. These are described in a subsequent section (Pollinator action on flowers).

| <img src="img/EvoBee-Bee-Behaviour-Flowchart-FNF.png" alt="Flow diagram for Forage Nearest flower strategy" width=95%/> | <img src="img/EvoBee-Bee-Behaviour-Flowchart-FAW.png" alt="Flow diagram for Forage Any flower strategy" width=95%/> |
|--|--|
| (a) *Forage Nearest* flower strategy | (b) *Forage Any* flower strategy |


> Figure 1. Flow charts for individual pollinator agents following (a) the *Forage Nearest* flower strategy, and (b) the *Forage Any* flower strategy. Bee-pollen refers to pollen carried on the body of the insect and potentially available for deposition on the stigma of a flower for pollination or pollen-clogging. Anther-pollen refers to pollen carried on a flower anther and potentially available for deposition on the body of a bee.

### Flower dynamics

At the start of a foraging phase, each flower begins with a fixed amount of anther pollen available for collection. Each flower also begins with a stigma free from pollen, but as the foraging phase progresses visiting pollinators may deposit pollen on its stigma. Pollinators may be allowed to deposit pollen from a different species onto the stigma (potentially pollen-clogging the flower) depending upon the configuration of the experiment. Configuration options are detailed in Table 2. A parameter specifies the capacity for pollen grains on a stigma. At the end of a foraging phase, every conspecific grain of pollen on the stigma forms a viable seed that enters the gene pool for the next generation of plants as described above (Overview of dynamics section). This is a simple proxy for the complexities of pollination in which several pollen grains may be required to fertilise an ovule [REF], but for the purposes of assessing the relative success of two competing species it is sufficient since  the two flowering plant  species we simulate are  treated consistently.

### Pollinator action on flowers

Each pollen grain carried by a pollinator visiting a flower is considered for transfer to the flower’s stigma subject to these limiting factors: the pollinator has a fixed maximum number of grains that it can transfer to the stigma during a visit; the stigma has a fixed maximum capacity for accepting pollen grains (above, section Flowers), and the stigma may or may not be susceptible to receiving pollen grains from a different species (above, section Flowers). Having taken all of these factors into account, if any pollen grains on the pollinator are eligible for transfer, then the determined number are picked at random from the pollinator for transferral to the stigma. Finally, the flower may transfer some of its anther pollen onto the pollinator’s body. Flower anthers start with a specified amount of pollen in each foraging phase; any available pollen on the anther is transferred to the pollinator, up to the fixed maximum transfer limit per visit.

##  Design concepts
    

### Basic principles

Our simulation builds upon the earlier simulation work of Waser (1978). One notable difference between our software and his is our use of a continuous spatial environment to avoid potential artefactual effects arising from modelling pollinator movements on a discrete grid [REFS: Bonnell et al 2016; Birch et al 2007]. Modern computing environments also allow us to simulate much larger environments than those that were feasible in 1978. We model up to 16,000 plants and 400 pollinators, running for up to 1000 generations, with each experimental condition repeated in 100 replicates (more in some cases), in contrast to 100 plants, 1 pollinator and up to 400 generations with 20 replicates in the early study. We have determined experimentally that the values we employ are sufficient to: confirm that our software’s behaviour matches the behaviour of Waser’s simulations; and, robustly generate the system behaviour we require to explore our own hypotheses (see section  Testing (Verification and Validation)). The novel results we report here arise from experimental configurations that were not considered in Waser’s original paper.
    

### Emergence

The key emergent property of interest in these experiments is whether or not both plant species X and Y can sustain viable coexistent populations for a given experimental configuration, or whether one species reaches fixation with the other dying out. We are primarily interested in how the pollen-clogging configuration (symmetric clogging, asymmetric clogging, or symmetric non-clogging) affects species coexistance.

### Pollinator perception

Under the default *Forage Nearest* flower strategy, pollinators can see flowers within 1 perceptual distance unit (pdu) of their current position, and move to the nearest flower seen within that distance  (Section,  Spatial Units).

Under the alternative *Forage Any* flower strategy, pollinators  move to a random flower anywhere in the entire environment. This strategy simulates an aspatial, well-mixed population of plants—it does not represent a real-world situation, but is of interest to indicate the underlying dynamics of the system.

Pollinators maintain a list of the last 5 individual flowers they have visited, and will not revisit a flower while it is on this list. The reader is reminded that the simulated insect pollinators are not flower constant. They will land on a target flower, as directed by the FN or FA strategy,  paying no heed of flower species.

### Interaction

The interactions between agents in the simulation are those between an individual pollinators, pollen and individual flowers. These interactions take place when the pollinator lands on a flower, as described in the Pollinator action on flowers section. There are no direct pollinator-pollinator or flower-flower interactions. It is possible for multiple pollinators to land and interact with  a  single flower within a time step. The order of their interactions is randomised.

### Stochasticity

The stochastic elements of the simulation are: placement of flowers and pollinators at the start of each foraging phase; the order in which pollinators are processed at each time step during the foraging phase; the direction a pollinator move if it doesn’t find a suitable nearby flower target in the FN strategy; the choice of target flower in the FA strategy; the choice of which individual pollen grains are transferred from a pollinator to a flower’s stigma upon landing; and, in the reproduction phase, the order in which viable seeds are considered for producing plants for the next generation.

### Observation

In these experiments, the main data recorded during experiments are, at the end of each generation, the generation number and the number of plants of each species X and Y currently in existence. For each experiment, we also record the full configuration set-up.

## Initialization


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTEwOTc1Njk3MTEsLTEwNzY4NTg4MDQsMT
AwNDYzMjIxNywxMjI4NzUzMzQ3LDczMjUyNTE3MywtNDc0ODAy
NzQ2LDg0NzA2MDE1OCwtNTgzNDM1MjI1LC0xNjgzNzExNTQ5LC
0yODU0NzA4M119
-->
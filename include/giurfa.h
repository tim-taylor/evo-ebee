/**
 * @file
 *
 * Definition of the Giurfa innate preference data. This file is intended to be included by
 * Hymentoptera.cpp only.
 */

#ifndef _GIURFA_H
#define _GIURFA_H

#include <vector>
#include <tuple>
#include "Hymenoptera.h"

// The following data is based upon the results shown in Fig 3 of Giurfa et al 1995 "Colour preferences
// of flower-naive honeybees". The data represents the normalised preferences for dominant wavelengths
// over the range 300-650nm in steps of 1nm. Each line is a triplet where the first item is the
// wavelength, the second is the normalised preference for that wavelength, and the third is the
// cumulative normalised preference of all wavelengths up to and including this one.
// The data was calculated in the Google spreadsheet
// https://docs.google.com/spreadsheets/d/1Ag2KZJXWme94-OCUq_0wfUpgLc0gx6QeXrfgxQnoL2g/edit#gid=0
// Data has been extrapolated from Giurfa's original data down to 300nm and up to 650nm by extending
// a horizontal line from his minimal and maximum points (366nm and 563nm) to the new limits.
std::vector<std::tuple<MarkerPoint, float, float>> Hymenoptera::m_sGiurfaCumulativeInnatePrefs {
    {300, 0.0022, 0.0022},
    {301, 0.0022, 0.0044},
    {302, 0.0022, 0.0066},
    {303, 0.0022, 0.0088},
    {304, 0.0022, 0.0110},
    {305, 0.0022, 0.0132},
    {306, 0.0022, 0.0154},
    {307, 0.0022, 0.0176},
    {308, 0.0022, 0.0198},
    {309, 0.0022, 0.0221},
    {310, 0.0022, 0.0243},
    {311, 0.0022, 0.0265},
    {312, 0.0022, 0.0287},
    {313, 0.0022, 0.0309},
    {314, 0.0022, 0.0331},
    {315, 0.0022, 0.0353},
    {316, 0.0022, 0.0375},
    {317, 0.0022, 0.0397},
    {318, 0.0022, 0.0419},
    {319, 0.0022, 0.0441},
    {320, 0.0022, 0.0463},
    {321, 0.0022, 0.0485},
    {322, 0.0022, 0.0507},
    {323, 0.0022, 0.0529},
    {324, 0.0022, 0.0551},
    {325, 0.0022, 0.0573},
    {326, 0.0022, 0.0595},
    {327, 0.0022, 0.0617},
    {328, 0.0022, 0.0639},
    {329, 0.0022, 0.0662},
    {330, 0.0022, 0.0684},
    {331, 0.0022, 0.0706},
    {332, 0.0022, 0.0728},
    {333, 0.0022, 0.0750},
    {334, 0.0022, 0.0772},
    {335, 0.0022, 0.0794},
    {336, 0.0022, 0.0816},
    {337, 0.0022, 0.0838},
    {338, 0.0022, 0.0860},
    {339, 0.0022, 0.0882},
    {340, 0.0022, 0.0904},
    {341, 0.0022, 0.0926},
    {342, 0.0022, 0.0948},
    {343, 0.0022, 0.0970},
    {344, 0.0022, 0.0992},
    {345, 0.0022, 0.1014},
    {346, 0.0022, 0.1036},
    {347, 0.0022, 0.1058},
    {348, 0.0022, 0.1080},
    {349, 0.0022, 0.1103},
    {350, 0.0022, 0.1125},
    {351, 0.0022, 0.1147},
    {352, 0.0022, 0.1169},
    {353, 0.0022, 0.1191},
    {354, 0.0022, 0.1213},
    {355, 0.0022, 0.1235},
    {356, 0.0022, 0.1257},
    {357, 0.0022, 0.1279},
    {358, 0.0022, 0.1301},
    {359, 0.0022, 0.1323},
    {360, 0.0022, 0.1345},
    {361, 0.0022, 0.1367},
    {362, 0.0022, 0.1389},
    {363, 0.0022, 0.1411},
    {364, 0.0022, 0.1433},
    {365, 0.0022, 0.1455},
    {366, 0.0022, 0.1477},
    {367, 0.0023, 0.1500},
    {368, 0.0023, 0.1523},
    {369, 0.0024, 0.1547},
    {370, 0.0025, 0.1572},
    {371, 0.0025, 0.1597},
    {372, 0.0026, 0.1623},
    {373, 0.0026, 0.1649},
    {374, 0.0027, 0.1676},
    {375, 0.0028, 0.1703},
    {376, 0.0028, 0.1732},
    {377, 0.0029, 0.1760},
    {378, 0.0029, 0.1790},
    {379, 0.0030, 0.1820},
    {380, 0.0031, 0.1850},
    {381, 0.0031, 0.1882},
    {382, 0.0032, 0.1914},
    {383, 0.0032, 0.1946},
    {384, 0.0033, 0.1979},
    {385, 0.0034, 0.2013},
    {386, 0.0034, 0.2047},
    {387, 0.0035, 0.2082},
    {388, 0.0036, 0.2117},
    {389, 0.0036, 0.2154},
    {390, 0.0037, 0.2190},
    {391, 0.0045, 0.2236},
    {392, 0.0054, 0.2290},
    {393, 0.0058, 0.2348},
    {394, 0.0062, 0.2410},
    {395, 0.0066, 0.2476},
    {396, 0.0070, 0.2546},
    {397, 0.0074, 0.2620},
    {398, 0.0078, 0.2699},
    {399, 0.0078, 0.2777},
    {400, 0.0078, 0.2854},
    {401, 0.0077, 0.2931},
    {402, 0.0077, 0.3008},
    {403, 0.0076, 0.3084},
    {404, 0.0076, 0.3160},
    {405, 0.0075, 0.3235},
    {406, 0.0075, 0.3310},
    {407, 0.0074, 0.3384},
    {408, 0.0074, 0.3458},
    {409, 0.0074, 0.3532},
    {410, 0.0070, 0.3601},
    {411, 0.0066, 0.3667},
    {412, 0.0062, 0.3729},
    {413, 0.0058, 0.3787},
    {414, 0.0054, 0.3840},
    {415, 0.0053, 0.3894},
    {416, 0.0052, 0.3946},
    {417, 0.0052, 0.3998},
    {418, 0.0051, 0.4049},
    {419, 0.0050, 0.4099},
    {420, 0.0049, 0.4148},
    {421, 0.0049, 0.4197},
    {422, 0.0048, 0.4245},
    {423, 0.0047, 0.4293},
    {424, 0.0047, 0.4339},
    {425, 0.0046, 0.4385},
    {426, 0.0045, 0.4430},
    {427, 0.0044, 0.4474},
    {428, 0.0044, 0.4518},
    {429, 0.0043, 0.4561},
    {430, 0.0042, 0.4603},
    {431, 0.0041, 0.4644},
    {432, 0.0041, 0.4685},
    {433, 0.0040, 0.4725},
    {434, 0.0039, 0.4764},
    {435, 0.0039, 0.4803},
    {436, 0.0039, 0.4842},
    {437, 0.0038, 0.4880},
    {438, 0.0038, 0.4918},
    {439, 0.0038, 0.4956},
    {440, 0.0037, 0.4993},
    {441, 0.0037, 0.5030},
    {442, 0.0037, 0.5067},
    {443, 0.0037, 0.5103},
    {444, 0.0036, 0.5140},
    {445, 0.0036, 0.5176},
    {446, 0.0036, 0.5211},
    {447, 0.0035, 0.5246},
    {448, 0.0035, 0.5281},
    {449, 0.0035, 0.5316},
    {450, 0.0034, 0.5351},
    {451, 0.0034, 0.5385},
    {452, 0.0034, 0.5419},
    {453, 0.0034, 0.5452},
    {454, 0.0033, 0.5485},
    {455, 0.0033, 0.5518},
    {456, 0.0033, 0.5551},
    {457, 0.0032, 0.5583},
    {458, 0.0032, 0.5615},
    {459, 0.0032, 0.5647},
    {460, 0.0031, 0.5678},
    {461, 0.0031, 0.5709},
    {462, 0.0031, 0.5740},
    {463, 0.0031, 0.5771},
    {464, 0.0030, 0.5801},
    {465, 0.0030, 0.5831},
    {466, 0.0030, 0.5860},
    {467, 0.0029, 0.5890},
    {468, 0.0029, 0.5919},
    {469, 0.0029, 0.5947},
    {470, 0.0028, 0.5976},
    {471, 0.0028, 0.6004},
    {472, 0.0028, 0.6032},
    {473, 0.0028, 0.6059},
    {474, 0.0027, 0.6086},
    {475, 0.0027, 0.6113},
    {476, 0.0027, 0.6140},
    {477, 0.0026, 0.6166},
    {478, 0.0026, 0.6192},
    {479, 0.0026, 0.6218},
    {480, 0.0025, 0.6243},
    {481, 0.0025, 0.6268},
    {482, 0.0025, 0.6293},
    {483, 0.0025, 0.6318},
    {484, 0.0024, 0.6341},
    {485, 0.0023, 0.6365},
    {486, 0.0023, 0.6388},
    {487, 0.0022, 0.6410},
    {488, 0.0022, 0.6432},
    {489, 0.0021, 0.6453},
    {490, 0.0021, 0.6474},
    {491, 0.0020, 0.6494},
    {492, 0.0020, 0.6514},
    {493, 0.0019, 0.6533},
    {494, 0.0019, 0.6551},
    {495, 0.0018, 0.6569},
    {496, 0.0017, 0.6586},
    {497, 0.0017, 0.6603},
    {498, 0.0016, 0.6620},
    {499, 0.0016, 0.6635},
    {500, 0.0015, 0.6651},
    {501, 0.0015, 0.6665},
    {502, 0.0016, 0.6681},
    {503, 0.0017, 0.6698},
    {504, 0.0018, 0.6717},
    {505, 0.0019, 0.6736},
    {506, 0.0021, 0.6757},
    {507, 0.0022, 0.6778},
    {508, 0.0023, 0.6801},
    {509, 0.0024, 0.6825},
    {510, 0.0025, 0.6850},
    {511, 0.0026, 0.6877},
    {512, 0.0028, 0.6904},
    {513, 0.0029, 0.6933},
    {514, 0.0030, 0.6963},
    {515, 0.0031, 0.6994},
    {516, 0.0032, 0.7027},
    {517, 0.0033, 0.7060},
    {518, 0.0035, 0.7095},
    {519, 0.0036, 0.7130},
    {520, 0.0037, 0.7167},
    {521, 0.0038, 0.7206},
    {522, 0.0039, 0.7245},
    {523, 0.0040, 0.7285},
    {524, 0.0042, 0.7327},
    {525, 0.0041, 0.7368},
    {526, 0.0041, 0.7410},
    {527, 0.0041, 0.7451},
    {528, 0.0041, 0.7492},
    {529, 0.0041, 0.7533},
    {530, 0.0041, 0.7573},
    {531, 0.0041, 0.7614},
    {532, 0.0040, 0.7654},
    {533, 0.0040, 0.7694},
    {534, 0.0040, 0.7734},
    {535, 0.0040, 0.7774},
    {536, 0.0040, 0.7814},
    {537, 0.0040, 0.7854},
    {538, 0.0039, 0.7893},
    {539, 0.0039, 0.7932},
    {540, 0.0039, 0.7971},
    {541, 0.0039, 0.8010},
    {542, 0.0039, 0.8049},
    {543, 0.0039, 0.8087},
    {544, 0.0038, 0.8126},
    {545, 0.0038, 0.8164},
    {546, 0.0038, 0.8202},
    {547, 0.0038, 0.8240},
    {548, 0.0038, 0.8278},
    {549, 0.0038, 0.8315},
    {550, 0.0037, 0.8353},
    {551, 0.0037, 0.8390},
    {552, 0.0037, 0.8427},
    {553, 0.0037, 0.8464},
    {554, 0.0037, 0.8501},
    {555, 0.0034, 0.8535},
    {556, 0.0032, 0.8567},
    {557, 0.0029, 0.8596},
    {558, 0.0027, 0.8623},
    {559, 0.0025, 0.8648},
    {560, 0.0022, 0.8670},
    {561, 0.0020, 0.8689},
    {562, 0.0017, 0.8706},
    {563, 0.0015, 0.8721},
    {564, 0.0015, 0.8736},
    {565, 0.0015, 0.8750},
    {566, 0.0015, 0.8765},
    {567, 0.0015, 0.8780},
    {568, 0.0015, 0.8795},
    {569, 0.0015, 0.8809},
    {570, 0.0015, 0.8824},
    {571, 0.0015, 0.8839},
    {572, 0.0015, 0.8853},
    {573, 0.0015, 0.8868},
    {574, 0.0015, 0.8883},
    {575, 0.0015, 0.8897},
    {576, 0.0015, 0.8912},
    {577, 0.0015, 0.8927},
    {578, 0.0015, 0.8942},
    {579, 0.0015, 0.8956},
    {580, 0.0015, 0.8971},
    {581, 0.0015, 0.8986},
    {582, 0.0015, 0.9000},
    {583, 0.0015, 0.9015},
    {584, 0.0015, 0.9030},
    {585, 0.0015, 0.9044},
    {586, 0.0015, 0.9059},
    {587, 0.0015, 0.9074},
    {588, 0.0015, 0.9089},
    {589, 0.0015, 0.9103},
    {590, 0.0015, 0.9118},
    {591, 0.0015, 0.9133},
    {592, 0.0015, 0.9147},
    {593, 0.0015, 0.9162},
    {594, 0.0015, 0.9177},
    {595, 0.0015, 0.9191},
    {596, 0.0015, 0.9206},
    {597, 0.0015, 0.9221},
    {598, 0.0015, 0.9236},
    {599, 0.0015, 0.9250},
    {600, 0.0015, 0.9265},
    {601, 0.0015, 0.9280},
    {602, 0.0015, 0.9294},
    {603, 0.0015, 0.9309},
    {604, 0.0015, 0.9324},
    {605, 0.0015, 0.9338},
    {606, 0.0015, 0.9353},
    {607, 0.0015, 0.9368},
    {608, 0.0015, 0.9383},
    {609, 0.0015, 0.9397},
    {610, 0.0015, 0.9412},
    {611, 0.0015, 0.9427},
    {612, 0.0015, 0.9441},
    {613, 0.0015, 0.9456},
    {614, 0.0015, 0.9471},
    {615, 0.0015, 0.9485},
    {616, 0.0015, 0.9500},
    {617, 0.0015, 0.9515},
    {618, 0.0015, 0.9530},
    {619, 0.0015, 0.9544},
    {620, 0.0015, 0.9559},
    {621, 0.0015, 0.9574},
    {622, 0.0015, 0.9588},
    {623, 0.0015, 0.9603},
    {624, 0.0015, 0.9618},
    {625, 0.0015, 0.9632},
    {626, 0.0015, 0.9647},
    {627, 0.0015, 0.9662},
    {628, 0.0015, 0.9677},
    {629, 0.0015, 0.9691},
    {630, 0.0015, 0.9706},
    {631, 0.0015, 0.9721},
    {632, 0.0015, 0.9735},
    {633, 0.0015, 0.9750},
    {634, 0.0015, 0.9765},
    {635, 0.0015, 0.9779},
    {636, 0.0015, 0.9794},
    {637, 0.0015, 0.9809},
    {638, 0.0015, 0.9824},
    {639, 0.0015, 0.9838},
    {640, 0.0015, 0.9853},
    {641, 0.0015, 0.9868},
    {642, 0.0015, 0.9882},
    {643, 0.0015, 0.9897},
    {644, 0.0015, 0.9912},
    {645, 0.0015, 0.9926},
    {646, 0.0015, 0.9941},
    {647, 0.0015, 0.9956},
    {648, 0.0015, 0.9971},
    {649, 0.0015, 0.9985},
    {650, 0.0015, 1.0000}
};

// The following data is based upon the results shown in Fig 3 of Giurfa et al 1995 "Colour preferences
// of flower-naive honeybees". The data represents the normalised preferences for dominant wavelengths
// over the range 360-570nm in steps of 1nm. Each line is a triplet where the first item is the
// wavelength, the second is the normalised preference for that wavelength, and the third is the
// cumulative normalised preference of all wavelengths up to and including this one.
// The data was calculated in the Google spreadsheet
// https://docs.google.com/spreadsheets/d/1Ag2KZJXWme94-OCUq_0wfUpgLc0gx6QeXrfgxQnoL2g/edit#gid=0
/*
std::vector<std::tuple<MarkerPoint, float, float>> Hymenoptera::m_sGiurfaCumulativeInnatePrefs {
    {360, 0.0025, 0.0025},
    {361, 0.0026, 0.0050},
    {362, 0.0026, 0.0077},
    {363, 0.0027, 0.0104},
    {364, 0.0028, 0.0132},
    {365, 0.0029, 0.0161},
    {366, 0.0030, 0.0191},
    {367, 0.0031, 0.0221},
    {368, 0.0031, 0.0253},
    {369, 0.0032, 0.0285},
    {370, 0.0033, 0.0318},
    {371, 0.0034, 0.0352},
    {372, 0.0035, 0.0386},
    {373, 0.0035, 0.0422},
    {374, 0.0036, 0.0458},
    {375, 0.0037, 0.0495},
    {376, 0.0038, 0.0533},
    {377, 0.0039, 0.0572},
    {378, 0.0040, 0.0612},
    {379, 0.0040, 0.0652},
    {380, 0.0041, 0.0693},
    {381, 0.0042, 0.0735},
    {382, 0.0043, 0.0778},
    {383, 0.0044, 0.0822},
    {384, 0.0045, 0.0867},
    {385, 0.0045, 0.0912},
    {386, 0.0046, 0.0958},
    {387, 0.0047, 0.1005},
    {388, 0.0048, 0.1053},
    {389, 0.0049, 0.1102},
    {390, 0.0050, 0.1151},
    {391, 0.0061, 0.1212},
    {392, 0.0073, 0.1285},
    {393, 0.0078, 0.1363},
    {394, 0.0084, 0.1447},
    {395, 0.0089, 0.1536},
    {396, 0.0095, 0.1630},
    {397, 0.0100, 0.1731},
    {398, 0.0106, 0.1836},
    {399, 0.0105, 0.1941},
    {400, 0.0104, 0.2046},
    {401, 0.0104, 0.2150},
    {402, 0.0103, 0.2253},
    {403, 0.0103, 0.2355},
    {404, 0.0102, 0.2457},
    {405, 0.0101, 0.2559},
    {406, 0.0101, 0.2660},
    {407, 0.0100, 0.2760},
    {408, 0.0100, 0.2860},
    {409, 0.0099, 0.2959},
    {410, 0.0094, 0.3052},
    {411, 0.0088, 0.3141},
    {412, 0.0083, 0.3224},
    {413, 0.0078, 0.3302},
    {414, 0.0073, 0.3375},
    {415, 0.0072, 0.3446},
    {416, 0.0071, 0.3517},
    {417, 0.0070, 0.3587},
    {418, 0.0069, 0.3655},
    {419, 0.0068, 0.3723},
    {420, 0.0067, 0.3790},
    {421, 0.0066, 0.3855},
    {422, 0.0065, 0.3920},
    {423, 0.0064, 0.3984},
    {424, 0.0063, 0.4046},
    {425, 0.0062, 0.4108},
    {426, 0.0061, 0.4169},
    {427, 0.0060, 0.4229},
    {428, 0.0059, 0.4287},
    {429, 0.0058, 0.4345},
    {430, 0.0057, 0.4402},
    {431, 0.0056, 0.4458},
    {432, 0.0055, 0.4513},
    {433, 0.0054, 0.4566},
    {434, 0.0053, 0.4619},
    {435, 0.0052, 0.4672},
    {436, 0.0052, 0.4724},
    {437, 0.0052, 0.4775},
    {438, 0.0051, 0.4826},
    {439, 0.0051, 0.4877},
    {440, 0.0050, 0.4928},
    {441, 0.0050, 0.4978},
    {442, 0.0050, 0.5027},
    {443, 0.0049, 0.5076},
    {444, 0.0049, 0.5125},
    {445, 0.0048, 0.5173},
    {446, 0.0048, 0.5221},
    {447, 0.0048, 0.5269},
    {448, 0.0047, 0.5316},
    {449, 0.0047, 0.5363},
    {450, 0.0046, 0.5409},
    {451, 0.0046, 0.5455},
    {452, 0.0046, 0.5501},
    {453, 0.0045, 0.5546},
    {454, 0.0045, 0.5591},
    {455, 0.0044, 0.5635},
    {456, 0.0044, 0.5679},
    {457, 0.0044, 0.5722},
    {458, 0.0043, 0.5766},
    {459, 0.0043, 0.5808},
    {460, 0.0042, 0.5851},
    {461, 0.0042, 0.5892},
    {462, 0.0042, 0.5934},
    {463, 0.0041, 0.5975},
    {464, 0.0041, 0.6016},
    {465, 0.0040, 0.6056},
    {466, 0.0040, 0.6096},
    {467, 0.0039, 0.6135},
    {468, 0.0039, 0.6174},
    {469, 0.0039, 0.6213},
    {470, 0.0038, 0.6251},
    {471, 0.0038, 0.6289},
    {472, 0.0037, 0.6327},
    {473, 0.0037, 0.6364},
    {474, 0.0037, 0.6400},
    {475, 0.0036, 0.6437},
    {476, 0.0036, 0.6472},
    {477, 0.0035, 0.6508},
    {478, 0.0035, 0.6543},
    {479, 0.0035, 0.6578},
    {480, 0.0034, 0.6612},
    {481, 0.0034, 0.6646},
    {482, 0.0033, 0.6679},
    {483, 0.0033, 0.6712},
    {484, 0.0032, 0.6744},
    {485, 0.0032, 0.6776},
    {486, 0.0031, 0.6807},
    {487, 0.0030, 0.6837},
    {488, 0.0029, 0.6866},
    {489, 0.0029, 0.6895},
    {490, 0.0028, 0.6923},
    {491, 0.0027, 0.6950},
    {492, 0.0026, 0.6976},
    {493, 0.0026, 0.7002},
    {494, 0.0025, 0.7027},
    {495, 0.0024, 0.7051},
    {496, 0.0023, 0.7074},
    {497, 0.0023, 0.7097},
    {498, 0.0022, 0.7119},
    {499, 0.0021, 0.7140},
    {500, 0.0021, 0.7161},
    {501, 0.0020, 0.7181},
    {502, 0.0021, 0.7202},
    {503, 0.0023, 0.7225},
    {504, 0.0025, 0.7250},
    {505, 0.0026, 0.7276},
    {506, 0.0028, 0.7304},
    {507, 0.0029, 0.7333},
    {508, 0.0031, 0.7364},
    {509, 0.0032, 0.7396},
    {510, 0.0034, 0.7430},
    {511, 0.0036, 0.7466},
    {512, 0.0037, 0.7503},
    {513, 0.0039, 0.7542},
    {514, 0.0040, 0.7582},
    {515, 0.0042, 0.7624},
    {516, 0.0043, 0.7667},
    {517, 0.0045, 0.7712},
    {518, 0.0047, 0.7759},
    {519, 0.0048, 0.7807},
    {520, 0.0050, 0.7857},
    {521, 0.0051, 0.7909},
    {522, 0.0053, 0.7961},
    {523, 0.0055, 0.8016},
    {524, 0.0056, 0.8072},
    {525, 0.0056, 0.8128},
    {526, 0.0056, 0.8184},
    {527, 0.0055, 0.8239},
    {528, 0.0055, 0.8294},
    {529, 0.0055, 0.8349},
    {530, 0.0055, 0.8404},
    {531, 0.0055, 0.8459},
    {532, 0.0054, 0.8513},
    {533, 0.0054, 0.8567},
    {534, 0.0054, 0.8621},
    {535, 0.0054, 0.8675},
    {536, 0.0053, 0.8728},
    {537, 0.0053, 0.8782},
    {538, 0.0053, 0.8835},
    {539, 0.0053, 0.8888},
    {540, 0.0053, 0.8940},
    {541, 0.0052, 0.8992},
    {542, 0.0052, 0.9045},
    {543, 0.0052, 0.9097},
    {544, 0.0052, 0.9148},
    {545, 0.0051, 0.9200},
    {546, 0.0051, 0.9251},
    {547, 0.0051, 0.9302},
    {548, 0.0051, 0.9353},
    {549, 0.0051, 0.9404},
    {550, 0.0050, 0.9454},
    {551, 0.0050, 0.9504},
    {552, 0.0050, 0.9554},
    {553, 0.0050, 0.9604},
    {554, 0.0050, 0.9653},
    {555, 0.0046, 0.9700},
    {556, 0.0043, 0.9743},
    {557, 0.0040, 0.9782},
    {558, 0.0036, 0.9818},
    {559, 0.0033, 0.9851},
    {560, 0.0030, 0.9881},
    {561, 0.0026, 0.9908},
    {562, 0.0023, 0.9931},
    {563, 0.0020, 0.9950},
    {564, 0.0017, 0.9967},
    {565, 0.0013, 0.9980},
    {566, 0.0010, 0.9990},
    {567, 0.0007, 0.9997},
    {568, 0.0003, 1.0000},
    {569, 0.0000, 1.0000},
    {570, 0.0000, 1.0000}
};
*/

// The following data is based upon the results shown in Fig 3 of Giurfa et al 1995 "Colour preferences
// of flower-naive honeybees". The data represents the normalised preferences for dominant wavelengths
// over the range 380-580nm in steps of 10nm. Each line is a triplet where the first item is the
// wavelength, the second is the normalised preference for that wavelength, and the third is the
// cumulative normalised preference of all wavelengths up to and including this one.
// The data was calculated in the Google spreadsheet
// https://docs.google.com/spreadsheets/d/1Ag2KZJXWme94-OCUq_0wfUpgLc0gx6QeXrfgxQnoL2g/edit#gid=0
//
/*
std::vector<std::tuple<MarkerPoint, float, float>> Hymenoptera::m_sGiurfaCumulativeInnatePrefs {
    {380, 0.04072, 0.04072},
    {390, 0.05090, 0.09162},
    {400, 0.10859, 0.20020},
    {410, 0.10180, 0.30200},
    {420, 0.07465, 0.37665},
    {430, 0.05429, 0.43095},
    {440, 0.05022, 0.48117},
    {450, 0.04615, 0.52732},
    {460, 0.04208, 0.56939},
    {470, 0.03800, 0.60740},
    {480, 0.03393, 0.64133},
    {490, 0.02715, 0.66848},
    {500, 0.02036, 0.68884},
    {510, 0.03529, 0.72413},
    {520, 0.05022, 0.77435},
    {530, 0.05655, 0.83090},
    {540, 0.05429, 0.88519},
    {550, 0.05203, 0.93722},
    {560, 0.03563, 0.97285},
    {570, 0.01697, 0.98982},
    {580, 0.01018, 1.00000}
};
*/

#endif /* _GIURFA_H */
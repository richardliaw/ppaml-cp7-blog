#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <chrono>
#include <random>
#include <numeric>
#include <string>
#include <memory>
#include <functional>
#include <utility>
#include "random/Bernoulli.h"
#include "random/Beta.h"
#include "random/Binomial.h"
#include "random/BooleanDistrib.h"
#include "random/Categorical.h"
#include "random/Exponential.h"
#include "random/Gaussian.h"
#include "random/Gamma.h"
#include "random/Geometric.h"
#include "random/Poisson.h"
#include "random/InvGamma.h"
#include "random/TruncatedGauss.h"
#include "random/UniformChoice.h"
#include "random/UniformInt.h"
#include "random/UniformReal.h"
#include "util/Hist.h"
#include "util/util.h"
#include "util/DynamicTable.h"


// MCMC Library included
#include "util/MCMC.h"
#include "util/util_MCMC.h"

// Matrix Library included
#include "armadillo"
#include "random/DiagGaussian.h"
#include "random/Dirichlet.h"
#include "random/Discrete.h"
#include "random/InvWishart.h"
#include "random/MultivarGaussian.h"
#include "random/MultivarGaussianIndep.h"
#include "random/Multinomial.h"
#include "random/UniformVector.h"
#include "random/PrecisionGaussian.h"
#include "util/Hist_matrix.h"
#include "util/util_matrix.h"
using namespace arma;

using namespace std;
using namespace swift::random;


int main();

namespace swift {

class _Var_bias;
class _Var_temporal_edge;
class _Var_spatial_edge;
class _Var_logit;
class _Var_region_rate;

const vector<string> __vecstr_instance_Week = {"weeks[0]", "weeks[1]", "weeks[2]", "weeks[3]", "weeks[4]", "weeks[5]", "weeks[6]", "weeks[7]", "weeks[8]", "weeks[9]", "weeks[10]", "weeks[11]", "weeks[12]", "weeks[13]", "weeks[14]", "weeks[15]", "weeks[16]", "weeks[17]", "weeks[18]", "weeks[19]", "weeks[20]", "weeks[21]", "weeks[22]", "weeks[23]", "weeks[24]", "weeks[25]", "weeks[26]", "weeks[27]", "weeks[28]", "weeks[29]", "weeks[30]", "weeks[31]", "weeks[32]", "weeks[33]", "weeks[34]", "weeks[35]", "weeks[36]", "weeks[37]", "weeks[38]", "weeks[39]", "weeks[40]", "weeks[41]", "weeks[42]", "weeks[43]", "weeks[44]", "weeks[45]", "weeks[46]", "weeks[47]", "weeks[48]", "weeks[49]", "weeks[50]", "weeks[51]", "weeks[52]", "weeks[53]", "weeks[54]", "weeks[55]", "weeks[56]", "weeks[57]", "weeks[58]", "weeks[59]", "weeks[60]", "weeks[61]", "weeks[62]", "weeks[63]", "weeks[64]", "weeks[65]", "weeks[66]", "weeks[67]", "weeks[68]", "weeks[69]", "weeks[70]", "weeks[71]", "weeks[72]", "weeks[73]", "weeks[74]", "weeks[75]", "weeks[76]", "weeks[77]", "weeks[78]", "weeks[79]", "weeks[80]", "weeks[81]", "weeks[82]", "weeks[83]", "weeks[84]", "weeks[85]", "weeks[86]", "weeks[87]", "weeks[88]", "weeks[89]", "weeks[90]", "weeks[91]", "weeks[92]", "weeks[93]", "weeks[94]", "weeks[95]", "weeks[96]", "weeks[97]", "weeks[98]", "weeks[99]", "weeks[100]", "weeks[101]", "weeks[102]"};
const vector<string> __vecstr_instance_TemporalPair = {"temporal_pairs[0]", "temporal_pairs[1]", "temporal_pairs[2]", "temporal_pairs[3]", "temporal_pairs[4]", "temporal_pairs[5]", "temporal_pairs[6]", "temporal_pairs[7]", "temporal_pairs[8]", "temporal_pairs[9]", "temporal_pairs[10]", "temporal_pairs[11]", "temporal_pairs[12]", "temporal_pairs[13]", "temporal_pairs[14]", "temporal_pairs[15]", "temporal_pairs[16]", "temporal_pairs[17]", "temporal_pairs[18]", "temporal_pairs[19]", "temporal_pairs[20]", "temporal_pairs[21]", "temporal_pairs[22]", "temporal_pairs[23]", "temporal_pairs[24]", "temporal_pairs[25]", "temporal_pairs[26]", "temporal_pairs[27]", "temporal_pairs[28]", "temporal_pairs[29]", "temporal_pairs[30]", "temporal_pairs[31]", "temporal_pairs[32]", "temporal_pairs[33]", "temporal_pairs[34]", "temporal_pairs[35]", "temporal_pairs[36]", "temporal_pairs[37]", "temporal_pairs[38]", "temporal_pairs[39]", "temporal_pairs[40]", "temporal_pairs[41]", "temporal_pairs[42]", "temporal_pairs[43]", "temporal_pairs[44]", "temporal_pairs[45]", "temporal_pairs[46]", "temporal_pairs[47]", "temporal_pairs[48]", "temporal_pairs[49]", "temporal_pairs[50]", "temporal_pairs[51]", "temporal_pairs[52]", "temporal_pairs[53]", "temporal_pairs[54]", "temporal_pairs[55]", "temporal_pairs[56]", "temporal_pairs[57]", "temporal_pairs[58]", "temporal_pairs[59]", "temporal_pairs[60]", "temporal_pairs[61]", "temporal_pairs[62]", "temporal_pairs[63]", "temporal_pairs[64]", "temporal_pairs[65]", "temporal_pairs[66]", "temporal_pairs[67]", "temporal_pairs[68]", "temporal_pairs[69]", "temporal_pairs[70]", "temporal_pairs[71]", "temporal_pairs[72]", "temporal_pairs[73]", "temporal_pairs[74]", "temporal_pairs[75]", "temporal_pairs[76]", "temporal_pairs[77]", "temporal_pairs[78]", "temporal_pairs[79]", "temporal_pairs[80]", "temporal_pairs[81]", "temporal_pairs[82]", "temporal_pairs[83]", "temporal_pairs[84]", "temporal_pairs[85]", "temporal_pairs[86]", "temporal_pairs[87]", "temporal_pairs[88]", "temporal_pairs[89]", "temporal_pairs[90]", "temporal_pairs[91]", "temporal_pairs[92]", "temporal_pairs[93]", "temporal_pairs[94]", "temporal_pairs[95]", "temporal_pairs[96]", "temporal_pairs[97]", "temporal_pairs[98]", "temporal_pairs[99]", "temporal_pairs[100]", "temporal_pairs[101]"};
const vector<string> __vecstr_instance_SpatialPair = {"spatial_pairs[0]", "spatial_pairs[1]", "spatial_pairs[2]", "spatial_pairs[3]", "spatial_pairs[4]", "spatial_pairs[5]", "spatial_pairs[6]", "spatial_pairs[7]", "spatial_pairs[8]", "spatial_pairs[9]", "spatial_pairs[10]", "spatial_pairs[11]", "spatial_pairs[12]", "spatial_pairs[13]", "spatial_pairs[14]", "spatial_pairs[15]", "spatial_pairs[16]", "spatial_pairs[17]", "spatial_pairs[18]", "spatial_pairs[19]", "spatial_pairs[20]", "spatial_pairs[21]", "spatial_pairs[22]", "spatial_pairs[23]", "spatial_pairs[24]", "spatial_pairs[25]", "spatial_pairs[26]", "spatial_pairs[27]", "spatial_pairs[28]", "spatial_pairs[29]", "spatial_pairs[30]", "spatial_pairs[31]", "spatial_pairs[32]", "spatial_pairs[33]", "spatial_pairs[34]", "spatial_pairs[35]", "spatial_pairs[36]", "spatial_pairs[37]", "spatial_pairs[38]", "spatial_pairs[39]", "spatial_pairs[40]", "spatial_pairs[41]", "spatial_pairs[42]", "spatial_pairs[43]", "spatial_pairs[44]", "spatial_pairs[45]", "spatial_pairs[46]", "spatial_pairs[47]", "spatial_pairs[48]", "spatial_pairs[49]", "spatial_pairs[50]", "spatial_pairs[51]", "spatial_pairs[52]", "spatial_pairs[53]", "spatial_pairs[54]", "spatial_pairs[55]", "spatial_pairs[56]", "spatial_pairs[57]", "spatial_pairs[58]", "spatial_pairs[59]", "spatial_pairs[60]", "spatial_pairs[61]", "spatial_pairs[62]", "spatial_pairs[63]", "spatial_pairs[64]", "spatial_pairs[65]", "spatial_pairs[66]", "spatial_pairs[67]", "spatial_pairs[68]", "spatial_pairs[69]", "spatial_pairs[70]", "spatial_pairs[71]", "spatial_pairs[72]", "spatial_pairs[73]", "spatial_pairs[74]", "spatial_pairs[75]", "spatial_pairs[76]", "spatial_pairs[77]", "spatial_pairs[78]", "spatial_pairs[79]", "spatial_pairs[80]", "spatial_pairs[81]", "spatial_pairs[82]", "spatial_pairs[83]", "spatial_pairs[84]", "spatial_pairs[85]", "spatial_pairs[86]", "spatial_pairs[87]", "spatial_pairs[88]", "spatial_pairs[89]", "spatial_pairs[90]", "spatial_pairs[91]", "spatial_pairs[92]", "spatial_pairs[93]", "spatial_pairs[94]", "spatial_pairs[95]", "spatial_pairs[96]", "spatial_pairs[97]", "spatial_pairs[98]", "spatial_pairs[99]", "spatial_pairs[100]", "spatial_pairs[101]", "spatial_pairs[102]", "spatial_pairs[103]", "spatial_pairs[104]", "spatial_pairs[105]", "spatial_pairs[106]", "spatial_pairs[107]", "spatial_pairs[108]", "spatial_pairs[109]", "spatial_pairs[110]", "spatial_pairs[111]", "spatial_pairs[112]", "spatial_pairs[113]", "spatial_pairs[114]", "spatial_pairs[115]", "spatial_pairs[116]", "spatial_pairs[117]", "spatial_pairs[118]", "spatial_pairs[119]", "spatial_pairs[120]", "spatial_pairs[121]", "spatial_pairs[122]", "spatial_pairs[123]", "spatial_pairs[124]", "spatial_pairs[125]", "spatial_pairs[126]", "spatial_pairs[127]", "spatial_pairs[128]", "spatial_pairs[129]", "spatial_pairs[130]", "spatial_pairs[131]", "spatial_pairs[132]", "spatial_pairs[133]", "spatial_pairs[134]", "spatial_pairs[135]", "spatial_pairs[136]", "spatial_pairs[137]", "spatial_pairs[138]", "spatial_pairs[139]", "spatial_pairs[140]", "spatial_pairs[141]", "spatial_pairs[142]", "spatial_pairs[143]", "spatial_pairs[144]", "spatial_pairs[145]", "spatial_pairs[146]", "spatial_pairs[147]", "spatial_pairs[148]", "spatial_pairs[149]", "spatial_pairs[150]", "spatial_pairs[151]", "spatial_pairs[152]", "spatial_pairs[153]", "spatial_pairs[154]", "spatial_pairs[155]", "spatial_pairs[156]", "spatial_pairs[157]", "spatial_pairs[158]", "spatial_pairs[159]", "spatial_pairs[160]", "spatial_pairs[161]", "spatial_pairs[162]", "spatial_pairs[163]", "spatial_pairs[164]", "spatial_pairs[165]", "spatial_pairs[166]", "spatial_pairs[167]", "spatial_pairs[168]", "spatial_pairs[169]", "spatial_pairs[170]", "spatial_pairs[171]", "spatial_pairs[172]", "spatial_pairs[173]", "spatial_pairs[174]", "spatial_pairs[175]", "spatial_pairs[176]", "spatial_pairs[177]", "spatial_pairs[178]", "spatial_pairs[179]", "spatial_pairs[180]", "spatial_pairs[181]", "spatial_pairs[182]", "spatial_pairs[183]", "spatial_pairs[184]", "spatial_pairs[185]", "spatial_pairs[186]", "spatial_pairs[187]", "spatial_pairs[188]", "spatial_pairs[189]", "spatial_pairs[190]", "spatial_pairs[191]", "spatial_pairs[192]", "spatial_pairs[193]", "spatial_pairs[194]", "spatial_pairs[195]", "spatial_pairs[196]", "spatial_pairs[197]", "spatial_pairs[198]", "spatial_pairs[199]", "spatial_pairs[200]", "spatial_pairs[201]", "spatial_pairs[202]", "spatial_pairs[203]", "spatial_pairs[204]", "spatial_pairs[205]", "spatial_pairs[206]", "spatial_pairs[207]", "spatial_pairs[208]", "spatial_pairs[209]", "spatial_pairs[210]", "spatial_pairs[211]", "spatial_pairs[212]", "spatial_pairs[213]", "spatial_pairs[214]", "spatial_pairs[215]", "spatial_pairs[216]", "spatial_pairs[217]", "spatial_pairs[218]", "spatial_pairs[219]", "spatial_pairs[220]", "spatial_pairs[221]", "spatial_pairs[222]", "spatial_pairs[223]", "spatial_pairs[224]", "spatial_pairs[225]", "spatial_pairs[226]", "spatial_pairs[227]", "spatial_pairs[228]", "spatial_pairs[229]", "spatial_pairs[230]", "spatial_pairs[231]", "spatial_pairs[232]", "spatial_pairs[233]", "spatial_pairs[234]", "spatial_pairs[235]", "spatial_pairs[236]", "spatial_pairs[237]", "spatial_pairs[238]", "spatial_pairs[239]", "spatial_pairs[240]", "spatial_pairs[241]", "spatial_pairs[242]", "spatial_pairs[243]", "spatial_pairs[244]", "spatial_pairs[245]", "spatial_pairs[246]", "spatial_pairs[247]", "spatial_pairs[248]", "spatial_pairs[249]", "spatial_pairs[250]", "spatial_pairs[251]", "spatial_pairs[252]", "spatial_pairs[253]", "spatial_pairs[254]", "spatial_pairs[255]", "spatial_pairs[256]", "spatial_pairs[257]", "spatial_pairs[258]", "spatial_pairs[259]", "spatial_pairs[260]", "spatial_pairs[261]", "spatial_pairs[262]", "spatial_pairs[263]", "spatial_pairs[264]", "spatial_pairs[265]", "spatial_pairs[266]", "spatial_pairs[267]", "spatial_pairs[268]", "spatial_pairs[269]", "spatial_pairs[270]", "spatial_pairs[271]", "spatial_pairs[272]", "spatial_pairs[273]", "spatial_pairs[274]", "spatial_pairs[275]", "spatial_pairs[276]", "spatial_pairs[277]", "spatial_pairs[278]", "spatial_pairs[279]", "spatial_pairs[280]", "spatial_pairs[281]", "spatial_pairs[282]", "spatial_pairs[283]", "spatial_pairs[284]", "spatial_pairs[285]", "spatial_pairs[286]", "spatial_pairs[287]", "spatial_pairs[288]", "spatial_pairs[289]", "spatial_pairs[290]", "spatial_pairs[291]", "spatial_pairs[292]", "spatial_pairs[293]", "spatial_pairs[294]", "spatial_pairs[295]", "spatial_pairs[296]", "spatial_pairs[297]", "spatial_pairs[298]", "spatial_pairs[299]", "spatial_pairs[300]", "spatial_pairs[301]", "spatial_pairs[302]", "spatial_pairs[303]", "spatial_pairs[304]", "spatial_pairs[305]", "spatial_pairs[306]", "spatial_pairs[307]", "spatial_pairs[308]", "spatial_pairs[309]", "spatial_pairs[310]", "spatial_pairs[311]", "spatial_pairs[312]", "spatial_pairs[313]", "spatial_pairs[314]", "spatial_pairs[315]", "spatial_pairs[316]", "spatial_pairs[317]", "spatial_pairs[318]", "spatial_pairs[319]", "spatial_pairs[320]", "spatial_pairs[321]", "spatial_pairs[322]", "spatial_pairs[323]", "spatial_pairs[324]", "spatial_pairs[325]", "spatial_pairs[326]", "spatial_pairs[327]", "spatial_pairs[328]", "spatial_pairs[329]", "spatial_pairs[330]", "spatial_pairs[331]", "spatial_pairs[332]", "spatial_pairs[333]", "spatial_pairs[334]", "spatial_pairs[335]", "spatial_pairs[336]", "spatial_pairs[337]", "spatial_pairs[338]", "spatial_pairs[339]", "spatial_pairs[340]", "spatial_pairs[341]", "spatial_pairs[342]", "spatial_pairs[343]", "spatial_pairs[344]", "spatial_pairs[345]", "spatial_pairs[346]", "spatial_pairs[347]", "spatial_pairs[348]", "spatial_pairs[349]", "spatial_pairs[350]", "spatial_pairs[351]", "spatial_pairs[352]", "spatial_pairs[353]", "spatial_pairs[354]", "spatial_pairs[355]", "spatial_pairs[356]", "spatial_pairs[357]", "spatial_pairs[358]", "spatial_pairs[359]", "spatial_pairs[360]", "spatial_pairs[361]", "spatial_pairs[362]", "spatial_pairs[363]", "spatial_pairs[364]", "spatial_pairs[365]", "spatial_pairs[366]", "spatial_pairs[367]", "spatial_pairs[368]", "spatial_pairs[369]", "spatial_pairs[370]", "spatial_pairs[371]", "spatial_pairs[372]", "spatial_pairs[373]", "spatial_pairs[374]", "spatial_pairs[375]", "spatial_pairs[376]", "spatial_pairs[377]", "spatial_pairs[378]", "spatial_pairs[379]", "spatial_pairs[380]", "spatial_pairs[381]", "spatial_pairs[382]", "spatial_pairs[383]", "spatial_pairs[384]", "spatial_pairs[385]", "spatial_pairs[386]", "spatial_pairs[387]", "spatial_pairs[388]", "spatial_pairs[389]", "spatial_pairs[390]", "spatial_pairs[391]", "spatial_pairs[392]", "spatial_pairs[393]", "spatial_pairs[394]", "spatial_pairs[395]", "spatial_pairs[396]", "spatial_pairs[397]", "spatial_pairs[398]", "spatial_pairs[399]", "spatial_pairs[400]", "spatial_pairs[401]", "spatial_pairs[402]", "spatial_pairs[403]", "spatial_pairs[404]", "spatial_pairs[405]", "spatial_pairs[406]", "spatial_pairs[407]", "spatial_pairs[408]", "spatial_pairs[409]", "spatial_pairs[410]", "spatial_pairs[411]", "spatial_pairs[412]", "spatial_pairs[413]", "spatial_pairs[414]", "spatial_pairs[415]", "spatial_pairs[416]", "spatial_pairs[417]", "spatial_pairs[418]", "spatial_pairs[419]", "spatial_pairs[420]", "spatial_pairs[421]", "spatial_pairs[422]", "spatial_pairs[423]", "spatial_pairs[424]", "spatial_pairs[425]", "spatial_pairs[426]", "spatial_pairs[427]", "spatial_pairs[428]", "spatial_pairs[429]", "spatial_pairs[430]", "spatial_pairs[431]", "spatial_pairs[432]", "spatial_pairs[433]", "spatial_pairs[434]", "spatial_pairs[435]", "spatial_pairs[436]", "spatial_pairs[437]", "spatial_pairs[438]", "spatial_pairs[439]", "spatial_pairs[440]", "spatial_pairs[441]", "spatial_pairs[442]", "spatial_pairs[443]", "spatial_pairs[444]", "spatial_pairs[445]", "spatial_pairs[446]", "spatial_pairs[447]", "spatial_pairs[448]", "spatial_pairs[449]", "spatial_pairs[450]", "spatial_pairs[451]", "spatial_pairs[452]", "spatial_pairs[453]", "spatial_pairs[454]", "spatial_pairs[455]", "spatial_pairs[456]", "spatial_pairs[457]", "spatial_pairs[458]", "spatial_pairs[459]", "spatial_pairs[460]", "spatial_pairs[461]", "spatial_pairs[462]", "spatial_pairs[463]", "spatial_pairs[464]", "spatial_pairs[465]", "spatial_pairs[466]", "spatial_pairs[467]", "spatial_pairs[468]", "spatial_pairs[469]", "spatial_pairs[470]", "spatial_pairs[471]", "spatial_pairs[472]", "spatial_pairs[473]", "spatial_pairs[474]", "spatial_pairs[475]", "spatial_pairs[476]", "spatial_pairs[477]", "spatial_pairs[478]", "spatial_pairs[479]", "spatial_pairs[480]", "spatial_pairs[481]", "spatial_pairs[482]", "spatial_pairs[483]", "spatial_pairs[484]", "spatial_pairs[485]", "spatial_pairs[486]", "spatial_pairs[487]", "spatial_pairs[488]", "spatial_pairs[489]", "spatial_pairs[490]", "spatial_pairs[491]", "spatial_pairs[492]", "spatial_pairs[493]", "spatial_pairs[494]", "spatial_pairs[495]", "spatial_pairs[496]", "spatial_pairs[497]", "spatial_pairs[498]", "spatial_pairs[499]", "spatial_pairs[500]", "spatial_pairs[501]", "spatial_pairs[502]", "spatial_pairs[503]", "spatial_pairs[504]", "spatial_pairs[505]", "spatial_pairs[506]", "spatial_pairs[507]", "spatial_pairs[508]", "spatial_pairs[509]", "spatial_pairs[510]", "spatial_pairs[511]", "spatial_pairs[512]", "spatial_pairs[513]", "spatial_pairs[514]", "spatial_pairs[515]", "spatial_pairs[516]", "spatial_pairs[517]", "spatial_pairs[518]", "spatial_pairs[519]", "spatial_pairs[520]", "spatial_pairs[521]", "spatial_pairs[522]", "spatial_pairs[523]", "spatial_pairs[524]", "spatial_pairs[525]", "spatial_pairs[526]", "spatial_pairs[527]", "spatial_pairs[528]", "spatial_pairs[529]", "spatial_pairs[530]", "spatial_pairs[531]", "spatial_pairs[532]", "spatial_pairs[533]", "spatial_pairs[534]", "spatial_pairs[535]", "spatial_pairs[536]", "spatial_pairs[537]", "spatial_pairs[538]", "spatial_pairs[539]", "spatial_pairs[540]", "spatial_pairs[541]", "spatial_pairs[542]", "spatial_pairs[543]", "spatial_pairs[544]", "spatial_pairs[545]", "spatial_pairs[546]", "spatial_pairs[547]", "spatial_pairs[548]", "spatial_pairs[549]", "spatial_pairs[550]", "spatial_pairs[551]", "spatial_pairs[552]", "spatial_pairs[553]", "spatial_pairs[554]", "spatial_pairs[555]", "spatial_pairs[556]", "spatial_pairs[557]", "spatial_pairs[558]", "spatial_pairs[559]", "spatial_pairs[560]", "spatial_pairs[561]", "spatial_pairs[562]", "spatial_pairs[563]", "spatial_pairs[564]", "spatial_pairs[565]", "spatial_pairs[566]", "spatial_pairs[567]", "spatial_pairs[568]", "spatial_pairs[569]", "spatial_pairs[570]", "spatial_pairs[571]", "spatial_pairs[572]", "spatial_pairs[573]", "spatial_pairs[574]", "spatial_pairs[575]", "spatial_pairs[576]", "spatial_pairs[577]", "spatial_pairs[578]", "spatial_pairs[579]", "spatial_pairs[580]", "spatial_pairs[581]", "spatial_pairs[582]", "spatial_pairs[583]", "spatial_pairs[584]", "spatial_pairs[585]", "spatial_pairs[586]", "spatial_pairs[587]", "spatial_pairs[588]", "spatial_pairs[589]", "spatial_pairs[590]", "spatial_pairs[591]", "spatial_pairs[592]", "spatial_pairs[593]", "spatial_pairs[594]", "spatial_pairs[595]", "spatial_pairs[596]", "spatial_pairs[597]", "spatial_pairs[598]", "spatial_pairs[599]", "spatial_pairs[600]", "spatial_pairs[601]", "spatial_pairs[602]", "spatial_pairs[603]", "spatial_pairs[604]", "spatial_pairs[605]", "spatial_pairs[606]", "spatial_pairs[607]", "spatial_pairs[608]", "spatial_pairs[609]", "spatial_pairs[610]", "spatial_pairs[611]", "spatial_pairs[612]", "spatial_pairs[613]", "spatial_pairs[614]", "spatial_pairs[615]", "spatial_pairs[616]", "spatial_pairs[617]", "spatial_pairs[618]", "spatial_pairs[619]", "spatial_pairs[620]", "spatial_pairs[621]", "spatial_pairs[622]", "spatial_pairs[623]", "spatial_pairs[624]", "spatial_pairs[625]", "spatial_pairs[626]", "spatial_pairs[627]", "spatial_pairs[628]", "spatial_pairs[629]", "spatial_pairs[630]", "spatial_pairs[631]", "spatial_pairs[632]", "spatial_pairs[633]", "spatial_pairs[634]", "spatial_pairs[635]", "spatial_pairs[636]", "spatial_pairs[637]", "spatial_pairs[638]", "spatial_pairs[639]", "spatial_pairs[640]", "spatial_pairs[641]", "spatial_pairs[642]", "spatial_pairs[643]", "spatial_pairs[644]", "spatial_pairs[645]", "spatial_pairs[646]", "spatial_pairs[647]", "spatial_pairs[648]", "spatial_pairs[649]", "spatial_pairs[650]", "spatial_pairs[651]", "spatial_pairs[652]", "spatial_pairs[653]", "spatial_pairs[654]", "spatial_pairs[655]", "spatial_pairs[656]", "spatial_pairs[657]", "spatial_pairs[658]", "spatial_pairs[659]", "spatial_pairs[660]", "spatial_pairs[661]", "spatial_pairs[662]", "spatial_pairs[663]", "spatial_pairs[664]", "spatial_pairs[665]", "spatial_pairs[666]", "spatial_pairs[667]", "spatial_pairs[668]", "spatial_pairs[669]", "spatial_pairs[670]", "spatial_pairs[671]", "spatial_pairs[672]", "spatial_pairs[673]", "spatial_pairs[674]", "spatial_pairs[675]", "spatial_pairs[676]", "spatial_pairs[677]", "spatial_pairs[678]", "spatial_pairs[679]", "spatial_pairs[680]", "spatial_pairs[681]", "spatial_pairs[682]", "spatial_pairs[683]", "spatial_pairs[684]", "spatial_pairs[685]", "spatial_pairs[686]", "spatial_pairs[687]", "spatial_pairs[688]", "spatial_pairs[689]", "spatial_pairs[690]", "spatial_pairs[691]", "spatial_pairs[692]", "spatial_pairs[693]", "spatial_pairs[694]", "spatial_pairs[695]", "spatial_pairs[696]", "spatial_pairs[697]", "spatial_pairs[698]", "spatial_pairs[699]", "spatial_pairs[700]", "spatial_pairs[701]", "spatial_pairs[702]", "spatial_pairs[703]", "spatial_pairs[704]", "spatial_pairs[705]", "spatial_pairs[706]", "spatial_pairs[707]", "spatial_pairs[708]", "spatial_pairs[709]", "spatial_pairs[710]", "spatial_pairs[711]", "spatial_pairs[712]", "spatial_pairs[713]", "spatial_pairs[714]", "spatial_pairs[715]", "spatial_pairs[716]", "spatial_pairs[717]", "spatial_pairs[718]", "spatial_pairs[719]", "spatial_pairs[720]", "spatial_pairs[721]", "spatial_pairs[722]", "spatial_pairs[723]", "spatial_pairs[724]", "spatial_pairs[725]", "spatial_pairs[726]", "spatial_pairs[727]", "spatial_pairs[728]", "spatial_pairs[729]", "spatial_pairs[730]", "spatial_pairs[731]", "spatial_pairs[732]", "spatial_pairs[733]", "spatial_pairs[734]", "spatial_pairs[735]", "spatial_pairs[736]", "spatial_pairs[737]", "spatial_pairs[738]", "spatial_pairs[739]", "spatial_pairs[740]", "spatial_pairs[741]", "spatial_pairs[742]", "spatial_pairs[743]", "spatial_pairs[744]", "spatial_pairs[745]", "spatial_pairs[746]", "spatial_pairs[747]", "spatial_pairs[748]", "spatial_pairs[749]", "spatial_pairs[750]", "spatial_pairs[751]", "spatial_pairs[752]", "spatial_pairs[753]", "spatial_pairs[754]", "spatial_pairs[755]", "spatial_pairs[756]", "spatial_pairs[757]", "spatial_pairs[758]", "spatial_pairs[759]", "spatial_pairs[760]", "spatial_pairs[761]", "spatial_pairs[762]", "spatial_pairs[763]", "spatial_pairs[764]", "spatial_pairs[765]", "spatial_pairs[766]", "spatial_pairs[767]", "spatial_pairs[768]", "spatial_pairs[769]", "spatial_pairs[770]", "spatial_pairs[771]", "spatial_pairs[772]", "spatial_pairs[773]", "spatial_pairs[774]", "spatial_pairs[775]", "spatial_pairs[776]", "spatial_pairs[777]", "spatial_pairs[778]", "spatial_pairs[779]", "spatial_pairs[780]", "spatial_pairs[781]", "spatial_pairs[782]", "spatial_pairs[783]", "spatial_pairs[784]", "spatial_pairs[785]", "spatial_pairs[786]", "spatial_pairs[787]", "spatial_pairs[788]", "spatial_pairs[789]", "spatial_pairs[790]", "spatial_pairs[791]", "spatial_pairs[792]", "spatial_pairs[793]", "spatial_pairs[794]", "spatial_pairs[795]", "spatial_pairs[796]", "spatial_pairs[797]", "spatial_pairs[798]", "spatial_pairs[799]", "spatial_pairs[800]", "spatial_pairs[801]", "spatial_pairs[802]", "spatial_pairs[803]", "spatial_pairs[804]", "spatial_pairs[805]", "spatial_pairs[806]", "spatial_pairs[807]", "spatial_pairs[808]", "spatial_pairs[809]", "spatial_pairs[810]", "spatial_pairs[811]", "spatial_pairs[812]", "spatial_pairs[813]", "spatial_pairs[814]", "spatial_pairs[815]", "spatial_pairs[816]", "spatial_pairs[817]", "spatial_pairs[818]", "spatial_pairs[819]", "spatial_pairs[820]", "spatial_pairs[821]", "spatial_pairs[822]", "spatial_pairs[823]", "spatial_pairs[824]", "spatial_pairs[825]", "spatial_pairs[826]", "spatial_pairs[827]", "spatial_pairs[828]", "spatial_pairs[829]", "spatial_pairs[830]", "spatial_pairs[831]", "spatial_pairs[832]", "spatial_pairs[833]", "spatial_pairs[834]", "spatial_pairs[835]", "spatial_pairs[836]", "spatial_pairs[837]", "spatial_pairs[838]", "spatial_pairs[839]", "spatial_pairs[840]", "spatial_pairs[841]", "spatial_pairs[842]", "spatial_pairs[843]", "spatial_pairs[844]", "spatial_pairs[845]", "spatial_pairs[846]", "spatial_pairs[847]", "spatial_pairs[848]", "spatial_pairs[849]", "spatial_pairs[850]", "spatial_pairs[851]", "spatial_pairs[852]", "spatial_pairs[853]", "spatial_pairs[854]", "spatial_pairs[855]", "spatial_pairs[856]", "spatial_pairs[857]", "spatial_pairs[858]", "spatial_pairs[859]", "spatial_pairs[860]", "spatial_pairs[861]", "spatial_pairs[862]", "spatial_pairs[863]", "spatial_pairs[864]", "spatial_pairs[865]", "spatial_pairs[866]", "spatial_pairs[867]", "spatial_pairs[868]", "spatial_pairs[869]", "spatial_pairs[870]", "spatial_pairs[871]", "spatial_pairs[872]", "spatial_pairs[873]", "spatial_pairs[874]", "spatial_pairs[875]", "spatial_pairs[876]", "spatial_pairs[877]", "spatial_pairs[878]", "spatial_pairs[879]", "spatial_pairs[880]", "spatial_pairs[881]", "spatial_pairs[882]", "spatial_pairs[883]", "spatial_pairs[884]", "spatial_pairs[885]", "spatial_pairs[886]", "spatial_pairs[887]", "spatial_pairs[888]", "spatial_pairs[889]", "spatial_pairs[890]", "spatial_pairs[891]", "spatial_pairs[892]", "spatial_pairs[893]", "spatial_pairs[894]", "spatial_pairs[895]", "spatial_pairs[896]", "spatial_pairs[897]", "spatial_pairs[898]", "spatial_pairs[899]", "spatial_pairs[900]", "spatial_pairs[901]", "spatial_pairs[902]", "spatial_pairs[903]", "spatial_pairs[904]", "spatial_pairs[905]", "spatial_pairs[906]", "spatial_pairs[907]", "spatial_pairs[908]", "spatial_pairs[909]", "spatial_pairs[910]", "spatial_pairs[911]", "spatial_pairs[912]", "spatial_pairs[913]", "spatial_pairs[914]", "spatial_pairs[915]", "spatial_pairs[916]", "spatial_pairs[917]", "spatial_pairs[918]", "spatial_pairs[919]", "spatial_pairs[920]", "spatial_pairs[921]", "spatial_pairs[922]", "spatial_pairs[923]", "spatial_pairs[924]", "spatial_pairs[925]", "spatial_pairs[926]", "spatial_pairs[927]", "spatial_pairs[928]", "spatial_pairs[929]", "spatial_pairs[930]", "spatial_pairs[931]", "spatial_pairs[932]", "spatial_pairs[933]", "spatial_pairs[934]", "spatial_pairs[935]", "spatial_pairs[936]", "spatial_pairs[937]", "spatial_pairs[938]", "spatial_pairs[939]", "spatial_pairs[940]", "spatial_pairs[941]", "spatial_pairs[942]", "spatial_pairs[943]", "spatial_pairs[944]", "spatial_pairs[945]", "spatial_pairs[946]", "spatial_pairs[947]", "spatial_pairs[948]", "spatial_pairs[949]", "spatial_pairs[950]", "spatial_pairs[951]", "spatial_pairs[952]", "spatial_pairs[953]", "spatial_pairs[954]", "spatial_pairs[955]", "spatial_pairs[956]", "spatial_pairs[957]", "spatial_pairs[958]", "spatial_pairs[959]", "spatial_pairs[960]", "spatial_pairs[961]", "spatial_pairs[962]", "spatial_pairs[963]", "spatial_pairs[964]", "spatial_pairs[965]", "spatial_pairs[966]", "spatial_pairs[967]", "spatial_pairs[968]", "spatial_pairs[969]", "spatial_pairs[970]", "spatial_pairs[971]", "spatial_pairs[972]", "spatial_pairs[973]", "spatial_pairs[974]", "spatial_pairs[975]", "spatial_pairs[976]", "spatial_pairs[977]", "spatial_pairs[978]", "spatial_pairs[979]", "spatial_pairs[980]", "spatial_pairs[981]", "spatial_pairs[982]", "spatial_pairs[983]", "spatial_pairs[984]", "spatial_pairs[985]", "spatial_pairs[986]", "spatial_pairs[987]", "spatial_pairs[988]", "spatial_pairs[989]", "spatial_pairs[990]", "spatial_pairs[991]", "spatial_pairs[992]", "spatial_pairs[993]", "spatial_pairs[994]", "spatial_pairs[995]", "spatial_pairs[996]", "spatial_pairs[997]", "spatial_pairs[998]", "spatial_pairs[999]", "spatial_pairs[1000]", "spatial_pairs[1001]", "spatial_pairs[1002]", "spatial_pairs[1003]", "spatial_pairs[1004]", "spatial_pairs[1005]", "spatial_pairs[1006]", "spatial_pairs[1007]", "spatial_pairs[1008]", "spatial_pairs[1009]", "spatial_pairs[1010]", "spatial_pairs[1011]", "spatial_pairs[1012]", "spatial_pairs[1013]", "spatial_pairs[1014]", "spatial_pairs[1015]", "spatial_pairs[1016]", "spatial_pairs[1017]", "spatial_pairs[1018]", "spatial_pairs[1019]", "spatial_pairs[1020]", "spatial_pairs[1021]", "spatial_pairs[1022]", "spatial_pairs[1023]", "spatial_pairs[1024]", "spatial_pairs[1025]", "spatial_pairs[1026]", "spatial_pairs[1027]", "spatial_pairs[1028]", "spatial_pairs[1029]", "spatial_pairs[1030]", "spatial_pairs[1031]", "spatial_pairs[1032]", "spatial_pairs[1033]", "spatial_pairs[1034]", "spatial_pairs[1035]", "spatial_pairs[1036]", "spatial_pairs[1037]", "spatial_pairs[1038]", "spatial_pairs[1039]", "spatial_pairs[1040]", "spatial_pairs[1041]", "spatial_pairs[1042]", "spatial_pairs[1043]", "spatial_pairs[1044]", "spatial_pairs[1045]", "spatial_pairs[1046]", "spatial_pairs[1047]", "spatial_pairs[1048]", "spatial_pairs[1049]", "spatial_pairs[1050]", "spatial_pairs[1051]", "spatial_pairs[1052]", "spatial_pairs[1053]", "spatial_pairs[1054]", "spatial_pairs[1055]", "spatial_pairs[1056]", "spatial_pairs[1057]", "spatial_pairs[1058]", "spatial_pairs[1059]", "spatial_pairs[1060]", "spatial_pairs[1061]", "spatial_pairs[1062]", "spatial_pairs[1063]", "spatial_pairs[1064]", "spatial_pairs[1065]", "spatial_pairs[1066]", "spatial_pairs[1067]", "spatial_pairs[1068]", "spatial_pairs[1069]", "spatial_pairs[1070]", "spatial_pairs[1071]", "spatial_pairs[1072]", "spatial_pairs[1073]", "spatial_pairs[1074]", "spatial_pairs[1075]", "spatial_pairs[1076]", "spatial_pairs[1077]", "spatial_pairs[1078]", "spatial_pairs[1079]", "spatial_pairs[1080]", "spatial_pairs[1081]", "spatial_pairs[1082]", "spatial_pairs[1083]", "spatial_pairs[1084]", "spatial_pairs[1085]", "spatial_pairs[1086]", "spatial_pairs[1087]", "spatial_pairs[1088]", "spatial_pairs[1089]", "spatial_pairs[1090]", "spatial_pairs[1091]", "spatial_pairs[1092]", "spatial_pairs[1093]", "spatial_pairs[1094]", "spatial_pairs[1095]", "spatial_pairs[1096]", "spatial_pairs[1097]", "spatial_pairs[1098]", "spatial_pairs[1099]", "spatial_pairs[1100]", "spatial_pairs[1101]", "spatial_pairs[1102]", "spatial_pairs[1103]", "spatial_pairs[1104]", "spatial_pairs[1105]", "spatial_pairs[1106]", "spatial_pairs[1107]", "spatial_pairs[1108]", "spatial_pairs[1109]", "spatial_pairs[1110]", "spatial_pairs[1111]", "spatial_pairs[1112]", "spatial_pairs[1113]", "spatial_pairs[1114]", "spatial_pairs[1115]", "spatial_pairs[1116]", "spatial_pairs[1117]", "spatial_pairs[1118]", "spatial_pairs[1119]", "spatial_pairs[1120]", "spatial_pairs[1121]", "spatial_pairs[1122]", "spatial_pairs[1123]", "spatial_pairs[1124]", "spatial_pairs[1125]", "spatial_pairs[1126]", "spatial_pairs[1127]", "spatial_pairs[1128]", "spatial_pairs[1129]", "spatial_pairs[1130]", "spatial_pairs[1131]", "spatial_pairs[1132]", "spatial_pairs[1133]", "spatial_pairs[1134]", "spatial_pairs[1135]", "spatial_pairs[1136]", "spatial_pairs[1137]", "spatial_pairs[1138]", "spatial_pairs[1139]", "spatial_pairs[1140]", "spatial_pairs[1141]", "spatial_pairs[1142]", "spatial_pairs[1143]", "spatial_pairs[1144]", "spatial_pairs[1145]", "spatial_pairs[1146]", "spatial_pairs[1147]", "spatial_pairs[1148]", "spatial_pairs[1149]", "spatial_pairs[1150]", "spatial_pairs[1151]", "spatial_pairs[1152]", "spatial_pairs[1153]", "spatial_pairs[1154]", "spatial_pairs[1155]", "spatial_pairs[1156]", "spatial_pairs[1157]", "spatial_pairs[1158]", "spatial_pairs[1159]", "spatial_pairs[1160]", "spatial_pairs[1161]", "spatial_pairs[1162]", "spatial_pairs[1163]", "spatial_pairs[1164]", "spatial_pairs[1165]", "spatial_pairs[1166]", "spatial_pairs[1167]", "spatial_pairs[1168]", "spatial_pairs[1169]", "spatial_pairs[1170]", "spatial_pairs[1171]", "spatial_pairs[1172]", "spatial_pairs[1173]", "spatial_pairs[1174]", "spatial_pairs[1175]", "spatial_pairs[1176]", "spatial_pairs[1177]", "spatial_pairs[1178]", "spatial_pairs[1179]", "spatial_pairs[1180]", "spatial_pairs[1181]", "spatial_pairs[1182]", "spatial_pairs[1183]", "spatial_pairs[1184]", "spatial_pairs[1185]", "spatial_pairs[1186]", "spatial_pairs[1187]", "spatial_pairs[1188]", "spatial_pairs[1189]", "spatial_pairs[1190]", "spatial_pairs[1191]", "spatial_pairs[1192]", "spatial_pairs[1193]", "spatial_pairs[1194]", "spatial_pairs[1195]", "spatial_pairs[1196]", "spatial_pairs[1197]", "spatial_pairs[1198]", "spatial_pairs[1199]", "spatial_pairs[1200]", "spatial_pairs[1201]", "spatial_pairs[1202]", "spatial_pairs[1203]", "spatial_pairs[1204]", "spatial_pairs[1205]", "spatial_pairs[1206]", "spatial_pairs[1207]", "spatial_pairs[1208]", "spatial_pairs[1209]", "spatial_pairs[1210]", "spatial_pairs[1211]", "spatial_pairs[1212]", "spatial_pairs[1213]", "spatial_pairs[1214]", "spatial_pairs[1215]", "spatial_pairs[1216]", "spatial_pairs[1217]", "spatial_pairs[1218]", "spatial_pairs[1219]", "spatial_pairs[1220]", "spatial_pairs[1221]", "spatial_pairs[1222]", "spatial_pairs[1223]", "spatial_pairs[1224]", "spatial_pairs[1225]", "spatial_pairs[1226]", "spatial_pairs[1227]", "spatial_pairs[1228]", "spatial_pairs[1229]", "spatial_pairs[1230]", "spatial_pairs[1231]", "spatial_pairs[1232]", "spatial_pairs[1233]", "spatial_pairs[1234]", "spatial_pairs[1235]", "spatial_pairs[1236]", "spatial_pairs[1237]", "spatial_pairs[1238]", "spatial_pairs[1239]", "spatial_pairs[1240]", "spatial_pairs[1241]", "spatial_pairs[1242]", "spatial_pairs[1243]", "spatial_pairs[1244]", "spatial_pairs[1245]", "spatial_pairs[1246]", "spatial_pairs[1247]", "spatial_pairs[1248]", "spatial_pairs[1249]", "spatial_pairs[1250]", "spatial_pairs[1251]", "spatial_pairs[1252]", "spatial_pairs[1253]", "spatial_pairs[1254]", "spatial_pairs[1255]", "spatial_pairs[1256]", "spatial_pairs[1257]", "spatial_pairs[1258]", "spatial_pairs[1259]", "spatial_pairs[1260]", "spatial_pairs[1261]", "spatial_pairs[1262]", "spatial_pairs[1263]", "spatial_pairs[1264]", "spatial_pairs[1265]", "spatial_pairs[1266]", "spatial_pairs[1267]", "spatial_pairs[1268]", "spatial_pairs[1269]", "spatial_pairs[1270]", "spatial_pairs[1271]", "spatial_pairs[1272]", "spatial_pairs[1273]", "spatial_pairs[1274]", "spatial_pairs[1275]", "spatial_pairs[1276]", "spatial_pairs[1277]", "spatial_pairs[1278]", "spatial_pairs[1279]", "spatial_pairs[1280]", "spatial_pairs[1281]", "spatial_pairs[1282]", "spatial_pairs[1283]", "spatial_pairs[1284]", "spatial_pairs[1285]", "spatial_pairs[1286]", "spatial_pairs[1287]", "spatial_pairs[1288]", "spatial_pairs[1289]", "spatial_pairs[1290]", "spatial_pairs[1291]", "spatial_pairs[1292]", "spatial_pairs[1293]", "spatial_pairs[1294]", "spatial_pairs[1295]", "spatial_pairs[1296]", "spatial_pairs[1297]", "spatial_pairs[1298]", "spatial_pairs[1299]", "spatial_pairs[1300]", "spatial_pairs[1301]", "spatial_pairs[1302]", "spatial_pairs[1303]", "spatial_pairs[1304]", "spatial_pairs[1305]", "spatial_pairs[1306]", "spatial_pairs[1307]", "spatial_pairs[1308]", "spatial_pairs[1309]", "spatial_pairs[1310]", "spatial_pairs[1311]", "spatial_pairs[1312]", "spatial_pairs[1313]", "spatial_pairs[1314]", "spatial_pairs[1315]", "spatial_pairs[1316]", "spatial_pairs[1317]", "spatial_pairs[1318]", "spatial_pairs[1319]", "spatial_pairs[1320]", "spatial_pairs[1321]", "spatial_pairs[1322]", "spatial_pairs[1323]", "spatial_pairs[1324]", "spatial_pairs[1325]", "spatial_pairs[1326]", "spatial_pairs[1327]", "spatial_pairs[1328]", "spatial_pairs[1329]", "spatial_pairs[1330]", "spatial_pairs[1331]", "spatial_pairs[1332]", "spatial_pairs[1333]", "spatial_pairs[1334]", "spatial_pairs[1335]", "spatial_pairs[1336]", "spatial_pairs[1337]", "spatial_pairs[1338]", "spatial_pairs[1339]", "spatial_pairs[1340]", "spatial_pairs[1341]", "spatial_pairs[1342]", "spatial_pairs[1343]", "spatial_pairs[1344]", "spatial_pairs[1345]", "spatial_pairs[1346]", "spatial_pairs[1347]", "spatial_pairs[1348]", "spatial_pairs[1349]", "spatial_pairs[1350]", "spatial_pairs[1351]", "spatial_pairs[1352]", "spatial_pairs[1353]", "spatial_pairs[1354]", "spatial_pairs[1355]", "spatial_pairs[1356]", "spatial_pairs[1357]", "spatial_pairs[1358]", "spatial_pairs[1359]", "spatial_pairs[1360]", "spatial_pairs[1361]", "spatial_pairs[1362]", "spatial_pairs[1363]", "spatial_pairs[1364]", "spatial_pairs[1365]", "spatial_pairs[1366]", "spatial_pairs[1367]", "spatial_pairs[1368]", "spatial_pairs[1369]", "spatial_pairs[1370]", "spatial_pairs[1371]", "spatial_pairs[1372]", "spatial_pairs[1373]", "spatial_pairs[1374]", "spatial_pairs[1375]", "spatial_pairs[1376]", "spatial_pairs[1377]", "spatial_pairs[1378]", "spatial_pairs[1379]", "spatial_pairs[1380]", "spatial_pairs[1381]", "spatial_pairs[1382]", "spatial_pairs[1383]", "spatial_pairs[1384]", "spatial_pairs[1385]", "spatial_pairs[1386]", "spatial_pairs[1387]", "spatial_pairs[1388]", "spatial_pairs[1389]", "spatial_pairs[1390]", "spatial_pairs[1391]", "spatial_pairs[1392]", "spatial_pairs[1393]", "spatial_pairs[1394]", "spatial_pairs[1395]", "spatial_pairs[1396]", "spatial_pairs[1397]", "spatial_pairs[1398]", "spatial_pairs[1399]", "spatial_pairs[1400]", "spatial_pairs[1401]", "spatial_pairs[1402]", "spatial_pairs[1403]", "spatial_pairs[1404]", "spatial_pairs[1405]", "spatial_pairs[1406]", "spatial_pairs[1407]", "spatial_pairs[1408]", "spatial_pairs[1409]", "spatial_pairs[1410]", "spatial_pairs[1411]", "spatial_pairs[1412]", "spatial_pairs[1413]", "spatial_pairs[1414]", "spatial_pairs[1415]", "spatial_pairs[1416]", "spatial_pairs[1417]", "spatial_pairs[1418]", "spatial_pairs[1419]", "spatial_pairs[1420]", "spatial_pairs[1421]", "spatial_pairs[1422]", "spatial_pairs[1423]", "spatial_pairs[1424]", "spatial_pairs[1425]", "spatial_pairs[1426]", "spatial_pairs[1427]", "spatial_pairs[1428]", "spatial_pairs[1429]", "spatial_pairs[1430]", "spatial_pairs[1431]", "spatial_pairs[1432]", "spatial_pairs[1433]", "spatial_pairs[1434]", "spatial_pairs[1435]", "spatial_pairs[1436]", "spatial_pairs[1437]", "spatial_pairs[1438]", "spatial_pairs[1439]", "spatial_pairs[1440]", "spatial_pairs[1441]", "spatial_pairs[1442]", "spatial_pairs[1443]", "spatial_pairs[1444]", "spatial_pairs[1445]", "spatial_pairs[1446]", "spatial_pairs[1447]", "spatial_pairs[1448]", "spatial_pairs[1449]", "spatial_pairs[1450]", "spatial_pairs[1451]", "spatial_pairs[1452]", "spatial_pairs[1453]", "spatial_pairs[1454]", "spatial_pairs[1455]", "spatial_pairs[1456]", "spatial_pairs[1457]", "spatial_pairs[1458]", "spatial_pairs[1459]", "spatial_pairs[1460]", "spatial_pairs[1461]", "spatial_pairs[1462]", "spatial_pairs[1463]", "spatial_pairs[1464]", "spatial_pairs[1465]", "spatial_pairs[1466]", "spatial_pairs[1467]", "spatial_pairs[1468]", "spatial_pairs[1469]", "spatial_pairs[1470]", "spatial_pairs[1471]", "spatial_pairs[1472]", "spatial_pairs[1473]", "spatial_pairs[1474]", "spatial_pairs[1475]", "spatial_pairs[1476]", "spatial_pairs[1477]", "spatial_pairs[1478]", "spatial_pairs[1479]"};
const vector<string> __vecstr_instance_Region = {"regions[0]", "regions[1]", "regions[2]", "regions[3]", "regions[4]", "regions[5]", "regions[6]", "regions[7]", "regions[8]", "regions[9]", "regions[10]", "regions[11]", "regions[12]", "regions[13]", "regions[14]", "regions[15]", "regions[16]", "regions[17]", "regions[18]", "regions[19]", "regions[20]", "regions[21]", "regions[22]", "regions[23]", "regions[24]"};
const vector<string> __vecstr_instance_County = {"counties[0]", "counties[1]", "counties[2]", "counties[3]", "counties[4]", "counties[5]", "counties[6]", "counties[7]", "counties[8]", "counties[9]", "counties[10]", "counties[11]", "counties[12]", "counties[13]", "counties[14]", "counties[15]", "counties[16]", "counties[17]", "counties[18]", "counties[19]", "counties[20]", "counties[21]", "counties[22]", "counties[23]", "counties[24]", "counties[25]", "counties[26]", "counties[27]", "counties[28]", "counties[29]", "counties[30]", "counties[31]", "counties[32]", "counties[33]", "counties[34]", "counties[35]", "counties[36]", "counties[37]", "counties[38]", "counties[39]", "counties[40]", "counties[41]", "counties[42]", "counties[43]", "counties[44]", "counties[45]", "counties[46]", "counties[47]", "counties[48]", "counties[49]", "counties[50]", "counties[51]", "counties[52]", "counties[53]", "counties[54]", "counties[55]", "counties[56]", "counties[57]", "counties[58]", "counties[59]", "counties[60]", "counties[61]", "counties[62]", "counties[63]", "counties[64]", "counties[65]", "counties[66]", "counties[67]", "counties[68]", "counties[69]", "counties[70]", "counties[71]", "counties[72]", "counties[73]", "counties[74]", "counties[75]", "counties[76]", "counties[77]", "counties[78]", "counties[79]", "counties[80]", "counties[81]", "counties[82]", "counties[83]", "counties[84]", "counties[85]", "counties[86]", "counties[87]", "counties[88]", "counties[89]", "counties[90]", "counties[91]", "counties[92]", "counties[93]", "counties[94]", "counties[95]", "counties[96]", "counties[97]", "counties[98]", "counties[99]", "counties[100]", "counties[101]", "counties[102]", "counties[103]", "counties[104]", "counties[105]", "counties[106]", "counties[107]", "counties[108]", "counties[109]", "counties[110]", "counties[111]", "counties[112]", "counties[113]", "counties[114]", "counties[115]", "counties[116]", "counties[117]", "counties[118]", "counties[119]", "counties[120]", "counties[121]", "counties[122]", "counties[123]", "counties[124]", "counties[125]", "counties[126]", "counties[127]", "counties[128]", "counties[129]", "counties[130]", "counties[131]", "counties[132]", "counties[133]", "counties[134]", "counties[135]", "counties[136]", "counties[137]", "counties[138]", "counties[139]", "counties[140]", "counties[141]", "counties[142]", "counties[143]", "counties[144]", "counties[145]", "counties[146]", "counties[147]", "counties[148]", "counties[149]", "counties[150]", "counties[151]", "counties[152]", "counties[153]", "counties[154]", "counties[155]", "counties[156]", "counties[157]", "counties[158]", "counties[159]", "counties[160]", "counties[161]", "counties[162]", "counties[163]", "counties[164]", "counties[165]", "counties[166]", "counties[167]", "counties[168]", "counties[169]", "counties[170]", "counties[171]", "counties[172]", "counties[173]", "counties[174]", "counties[175]", "counties[176]", "counties[177]", "counties[178]", "counties[179]", "counties[180]", "counties[181]", "counties[182]", "counties[183]", "counties[184]", "counties[185]", "counties[186]", "counties[187]", "counties[188]", "counties[189]", "counties[190]", "counties[191]", "counties[192]", "counties[193]", "counties[194]", "counties[195]", "counties[196]", "counties[197]", "counties[198]", "counties[199]", "counties[200]", "counties[201]", "counties[202]", "counties[203]", "counties[204]", "counties[205]", "counties[206]", "counties[207]", "counties[208]", "counties[209]", "counties[210]", "counties[211]", "counties[212]", "counties[213]", "counties[214]", "counties[215]", "counties[216]", "counties[217]", "counties[218]", "counties[219]", "counties[220]", "counties[221]", "counties[222]", "counties[223]", "counties[224]", "counties[225]", "counties[226]", "counties[227]", "counties[228]", "counties[229]", "counties[230]", "counties[231]", "counties[232]", "counties[233]", "counties[234]", "counties[235]", "counties[236]", "counties[237]", "counties[238]", "counties[239]", "counties[240]", "counties[241]", "counties[242]", "counties[243]", "counties[244]", "counties[245]", "counties[246]", "counties[247]", "counties[248]", "counties[249]", "counties[250]", "counties[251]", "counties[252]", "counties[253]", "counties[254]", "counties[255]", "counties[256]", "counties[257]", "counties[258]", "counties[259]", "counties[260]", "counties[261]", "counties[262]", "counties[263]", "counties[264]", "counties[265]", "counties[266]", "counties[267]", "counties[268]", "counties[269]", "counties[270]", "counties[271]", "counties[272]", "counties[273]", "counties[274]", "counties[275]", "counties[276]"};
void _eval_query();
void _init_storage();
void _init_world();
void _garbage_collection();
void _print_answer();
const int _TOT_LOOP = 8000000;
const int _BURN_IN = 7999900;
int _tot_round = -7999900;
const double __fixed_beta1 = 1.35000000;
const double __fixed_beta2 = 0.50000000;
const double __fixed_rho = 0.25000000;
const double __fixed_tau1 = 0.50000000;
const mat __fixed_county_map = loadRealMatrix("data_processed/county_map.txt");
const mat __fixed_region_pop = loadRealMatrix("data_processed/region_pops.txt");
const mat __fixed_covariates1 = loadRealMatrix("data_processed/covariates1.txt");
const mat __fixed_covariates2 = loadRealMatrix("data_processed/covariates2.txt");
const mat __fixed_priors = loadRealMatrix("data_processed/priors.txt");
const mat __fixed_D = loadRealMatrix("data_processed/D.txt");
const mat __fixed_W = loadRealMatrix("data_processed/W.txt");
const mat __fixed_observations = loadRealMatrix("data_processed/obs.txt");
const mat __fixed_spatial_obs = loadRealMatrix("data_processed/spatial_obs.txt");
const mat __fixed_temporal_obs = loadRealMatrix("data_processed/temporal_obs.txt");
int __fixed_toWeek(int);
int __fixed_toCounty(int);
double __fixed_sigmoid(double);
class _Var_bias: public BayesVar<double> {
public:
  _Var_bias();
  string getname();
  double& getval();
  double& getcache();
  void clear();
  double getlikeli();
  double getcachelikeli();
  void sample();
  void sample_cache();
  void active_edge();
  void remove_edge();
  void mcmc_resample();
};
_Var_bias* _mem_bias;
class _Var_temporal_edge: public BayesVar<char> {
public:
  int c;
  int t;
  _Var_temporal_edge(int,int);
  string getname();
  char& getval();
  char& getcache();
  void clear();
  double getlikeli();
  double getcachelikeli();
  void sample();
  void sample_cache();
  void active_edge();
  void remove_edge();
  void mcmc_resample();
};
DynamicTable<_Var_temporal_edge*,2> _mem_temporal_edge;
class _Var_spatial_edge: public BayesVar<char> {
public:
  int t;
  int s;
  _Var_spatial_edge(int,int);
  string getname();
  char& getval();
  char& getcache();
  void clear();
  double getlikeli();
  double getcachelikeli();
  void sample();
  void sample_cache();
  void active_edge();
  void remove_edge();
  void mcmc_resample();
};
DynamicTable<_Var_spatial_edge*,2> _mem_spatial_edge;
class _Var_logit: public BayesVar<double> {
public:
  int c;
  int t;
  _Var_logit(int,int);
  string getname();
  double& getval();
  double& getcache();
  void clear();
  double getlikeli();
  double getcachelikeli();
  void sample();
  void sample_cache();
  void active_edge();
  void remove_edge();
  void mcmc_resample();
};
DynamicTable<_Var_logit*,2> _mem_logit;
class _Var_region_rate: public BayesVar<double> {
public:
  int r;
  int t;
  _Var_region_rate(int,int);
  string getname();
  double& getval();
  double& getcache();
  void clear();
  double getlikeli();
  double getcachelikeli();
  void sample();
  void sample_cache();
  void active_edge();
  void remove_edge();
  void mcmc_resample();
};
DynamicTable<_Var_region_rate*,2> _mem_region_rate;
Gaussian Gaussian28678832;
BooleanDistrib BooleanDistrib28690048;
BooleanDistrib BooleanDistrib28694048;
Gaussian Gaussian28698176;
Gaussian Gaussian28870544;
Hist<double> _answer_0 = Hist<double>(false, 20);
Hist<double> _answer_1 = Hist<double>(false, 20);
Hist<double> _answer_2 = Hist<double>(false, 20);
Hist<double> _answer_3 = Hist<double>(false, 20);
DynamicTable<Hist<double>*,2> _answer_4;
void sample();

void _eval_query()
{
  _tot_round++;
  if (_tot_round<=0)
    return ;
  _answer_0.add(__fixed_tau1,1);
  _answer_1.add(__fixed_rho,1);
  _answer_2.add(__fixed_beta1,1);
  _answer_3.add(__fixed_beta2,1);
  for (int c = 0;c<277;c++)
  for (int t = 0;t<103;t++)
  _answer_4[c][t]->add(_mem_logit[c][t]->getval(),1);


}
void _init_storage()
{
  _mem_bias=new _Var_bias();
  _mem_temporal_edge.resize(0,277);
  _mem_temporal_edge.resize(1,102);
  for (int c = 0;c<277;c++)
  {
    for (int t = 0;t<102;t++)
    {
      _mem_temporal_edge[c][t]=new _Var_temporal_edge(c, t);
    }

  }

  _mem_spatial_edge.resize(0,103);
  _mem_spatial_edge.resize(1,1480);
  for (int t = 0;t<103;t++)
  {
    for (int s = 0;s<1480;s++)
    {
      _mem_spatial_edge[t][s]=new _Var_spatial_edge(t, s);
    }

  }

  _mem_logit.resize(0,277);
  _mem_logit.resize(1,103);
  for (int c = 0;c<277;c++)
  {
    for (int t = 0;t<103;t++)
    {
      _mem_logit[c][t]=new _Var_logit(c, t);
    }

  }

  _mem_region_rate.resize(0,25);
  _mem_region_rate.resize(1,103);
  for (int r = 0;r<25;r++)
  {
    for (int t = 0;t<103;t++)
    {
      _mem_region_rate[r][t]=new _Var_region_rate(r, t);
    }

  }

  Gaussian28678832.init(-5.00000000,0.10000000);
  _answer_4.resize(0,277);
  _answer_4.resize(1,103);
  for (int c = 0;c<277;c++)
  {
    for (int t = 0;t<103;t++)
    {
      _answer_4[c][t]=new Hist<double>(false, 20);
    }

  }

}
void _init_world()
{
  for (int c = 0;c<277;c++)
  for (int t = 0;t<102;t++)
  _util_set_evidence<char>(_mem_temporal_edge[c][t],1);


  for (int t = 0;t<103;t++)
  for (int s = 0;s<1480;s++)
  _util_set_evidence<char>(_mem_spatial_edge[t][s],1);


  for (int r = 0;r<25;r++)
  for (int t = 0;t<103;t++)
  if (__fixed_observations(t,r)>-1.00000000)
    _util_set_evidence<double>(_mem_region_rate[r][t],__fixed_observations(t,r));


}
void _garbage_collection()
{
  _free_obj(_mem_bias);
  _free_obj(_mem_temporal_edge);
  _free_obj(_mem_spatial_edge);
  _free_obj(_mem_logit);
  _free_obj(_mem_region_rate);
}
void _print_answer()
{
  _answer_0.print("tau1");
  _answer_1.print("rho");
  _answer_2.print("beta1");
  _answer_3.print("beta2");
  char buffer4[256];
  for (int c = 0;c<277;c++)
  for (int t = 0;t<103;t++)
  {
    sprintf(buffer4,"logit(County[%d], Week[%d])\n",c,t);
    _answer_4[c][t]->print(buffer4);
  }


}
int __fixed_toWeek(int i)
{
  return i;
}
int __fixed_toCounty(int i)
{
  return i;
}
double __fixed_sigmoid(double value)
{
  return 1.00000000/(1.00000000+exp(-1.00000000*value));
}
_Var_bias::_Var_bias()
{}
string _Var_bias::getname()
{
  return "bias";
}
double& _Var_bias::getval()
{
  return getval_arg(this);
}
double& _Var_bias::getcache()
{
  return getcache_arg(this);
}
void _Var_bias::clear()
{
  return clear_arg(this);
}
double _Var_bias::getlikeli()
{
  return Gaussian28678832.loglikeli(val);
}
double _Var_bias::getcachelikeli()
{
  auto _t_val = getcache();
  return Gaussian28678832.loglikeli(_t_val);
}
void _Var_bias::sample()
{
  val=Gaussian28678832.gen();
}
void _Var_bias::sample_cache()
{
  cache_val=Gaussian28678832.gen();
}
void _Var_bias::active_edge()
{}
void _Var_bias::remove_edge()
{}
void _Var_bias::mcmc_resample()
{
  mh_parent_resample_arg(this);
}
_Var_temporal_edge::_Var_temporal_edge(int _c, int _t):c(_c),t(_t)
{}
string _Var_temporal_edge::getname()
{
  return "temporal_edge";
}
char& _Var_temporal_edge::getval()
{
  return getval_arg(this);
}
char& _Var_temporal_edge::getcache()
{
  return getcache_arg(this);
}
void _Var_temporal_edge::clear()
{
  return clear_arg(this);
}
double _Var_temporal_edge::getlikeli()
{
  return BooleanDistrib28690048.init(exp(1.00000000*__fixed_tau1*(_mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,0)))]->getval()-_mem_bias->getval())*(_mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,1)))]->getval()-_mem_bias->getval()))),BooleanDistrib28690048.loglikeli(val);
}
double _Var_temporal_edge::getcachelikeli()
{
  auto _t_val = getcache();
  return BooleanDistrib28690048.init(exp(1.00000000*__fixed_tau1*(_mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,0)))]->getcache()-_mem_bias->getcache())*(_mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,1)))]->getcache()-_mem_bias->getcache()))),BooleanDistrib28690048.loglikeli(_t_val);
}
void _Var_temporal_edge::sample()
{
  val=(BooleanDistrib28690048.init(exp(1.00000000*__fixed_tau1*(_mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,0)))]->getval()-_mem_bias->getval())*(_mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,1)))]->getval()-_mem_bias->getval()))),BooleanDistrib28690048.gen());
}
void _Var_temporal_edge::sample_cache()
{
  cache_val=(BooleanDistrib28690048.init(exp(1.00000000*__fixed_tau1*(_mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,0)))]->getcache()-_mem_bias->getcache())*(_mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,1)))]->getcache()-_mem_bias->getcache()))),BooleanDistrib28690048.gen());
}
void _Var_temporal_edge::active_edge()
{
  _mem_bias->add_contig(this);
  _mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,0)))]->add_contig(this);
  _mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,1)))]->add_contig(this);
  _mem_bias->add_child(this);
  _mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,0)))]->add_child(this);
  _mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,1)))]->add_child(this);
}
void _Var_temporal_edge::remove_edge()
{
  _mem_bias->erase_contig(this);
  _mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,0)))]->erase_contig(this);
  _mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,1)))]->erase_contig(this);
  _mem_bias->erase_child(this);
  _mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,0)))]->erase_child(this);
  _mem_logit[c][__fixed_toWeek(toInt(__fixed_temporal_obs(t,1)))]->erase_child(this);
}
void _Var_temporal_edge::mcmc_resample()
{
  mh_parent_resample_arg(this);
}
_Var_spatial_edge::_Var_spatial_edge(int _t, int _s):t(_t),s(_s)
{}
string _Var_spatial_edge::getname()
{
  return "spatial_edge";
}
char& _Var_spatial_edge::getval()
{
  return getval_arg(this);
}
char& _Var_spatial_edge::getcache()
{
  return getcache_arg(this);
}
void _Var_spatial_edge::clear()
{
  return clear_arg(this);
}
double _Var_spatial_edge::getlikeli()
{
  return BooleanDistrib28694048.init(exp(1.00000000*__fixed_tau1*__fixed_rho*(_mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,0)))][t]->getval()-_mem_bias->getval())*(_mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,1)))][t]->getval()-_mem_bias->getval()))),BooleanDistrib28694048.loglikeli(val);
}
double _Var_spatial_edge::getcachelikeli()
{
  auto _t_val = getcache();
  return BooleanDistrib28694048.init(exp(1.00000000*__fixed_tau1*__fixed_rho*(_mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,0)))][t]->getcache()-_mem_bias->getcache())*(_mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,1)))][t]->getcache()-_mem_bias->getcache()))),BooleanDistrib28694048.loglikeli(_t_val);
}
void _Var_spatial_edge::sample()
{
  val=(BooleanDistrib28694048.init(exp(1.00000000*__fixed_tau1*__fixed_rho*(_mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,0)))][t]->getval()-_mem_bias->getval())*(_mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,1)))][t]->getval()-_mem_bias->getval()))),BooleanDistrib28694048.gen());
}
void _Var_spatial_edge::sample_cache()
{
  cache_val=(BooleanDistrib28694048.init(exp(1.00000000*__fixed_tau1*__fixed_rho*(_mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,0)))][t]->getcache()-_mem_bias->getcache())*(_mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,1)))][t]->getcache()-_mem_bias->getcache()))),BooleanDistrib28694048.gen());
}
void _Var_spatial_edge::active_edge()
{
  _mem_bias->add_contig(this);
  _mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,0)))][t]->add_contig(this);
  _mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,1)))][t]->add_contig(this);
  _mem_bias->add_child(this);
  _mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,0)))][t]->add_child(this);
  _mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,1)))][t]->add_child(this);
}
void _Var_spatial_edge::remove_edge()
{
  _mem_bias->erase_contig(this);
  _mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,0)))][t]->erase_contig(this);
  _mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,1)))][t]->erase_contig(this);
  _mem_bias->erase_child(this);
  _mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,0)))][t]->erase_child(this);
  _mem_logit[__fixed_toCounty(toInt(__fixed_spatial_obs(s,1)))][t]->erase_child(this);
}
void _Var_spatial_edge::mcmc_resample()
{
  mh_parent_resample_arg(this);
}
_Var_logit::_Var_logit(int _c, int _t):c(_c),t(_t)
{}
string _Var_logit::getname()
{
  return "logit";
}
double& _Var_logit::getval()
{
  return getval_arg(this);
}
double& _Var_logit::getcache()
{
  return getcache_arg(this);
}
void _Var_logit::clear()
{
  return clear_arg(this);
}
double _Var_logit::getlikeli()
{
  return Gaussian28698176.init(_mem_bias->getval()+__fixed_beta1*__fixed_covariates1(c,t)+__fixed_beta2*__fixed_covariates2(c,t),__fixed_D[c]),Gaussian28698176.loglikeli(val);
}
double _Var_logit::getcachelikeli()
{
  auto _t_val = getcache();
  return Gaussian28698176.init(_mem_bias->getcache()+__fixed_beta1*__fixed_covariates1(c,t)+__fixed_beta2*__fixed_covariates2(c,t),__fixed_D[c]),Gaussian28698176.loglikeli(_t_val);
}
void _Var_logit::sample()
{
  val=(Gaussian28698176.init(_mem_bias->getval()+__fixed_beta1*__fixed_covariates1(c,t)+__fixed_beta2*__fixed_covariates2(c,t),__fixed_D[c]),Gaussian28698176.gen());
}
void _Var_logit::sample_cache()
{
  cache_val=(Gaussian28698176.init(_mem_bias->getcache()+__fixed_beta1*__fixed_covariates1(c,t)+__fixed_beta2*__fixed_covariates2(c,t),__fixed_D[c]),Gaussian28698176.gen());
}
void _Var_logit::active_edge()
{
  _mem_bias->add_contig(this);
  _mem_bias->add_child(this);
}
void _Var_logit::remove_edge()
{
  _mem_bias->erase_contig(this);
  _mem_bias->erase_child(this);
}
void _Var_logit::mcmc_resample()
{
  mh_parent_resample_arg(this);
}
_Var_region_rate::_Var_region_rate(int _r, int _t):r(_r),t(_t)
{}
string _Var_region_rate::getname()
{
  return "region_rate";
}
double& _Var_region_rate::getval()
{
  return getval_arg(this);
}
double& _Var_region_rate::getcache()
{
  return getcache_arg(this);
}
void _Var_region_rate::clear()
{
  return clear_arg(this);
}
double _Var_region_rate::getlikeli()
{
  return Gaussian28870544.init(dot(__fixed_county_map.row(r),vstack({__fixed_sigmoid(_mem_logit[0][t]->getval()), __fixed_sigmoid(_mem_logit[1][t]->getval()), __fixed_sigmoid(_mem_logit[2][t]->getval()), __fixed_sigmoid(_mem_logit[3][t]->getval()), __fixed_sigmoid(_mem_logit[4][t]->getval()), __fixed_sigmoid(_mem_logit[5][t]->getval()), __fixed_sigmoid(_mem_logit[6][t]->getval()), __fixed_sigmoid(_mem_logit[7][t]->getval()), __fixed_sigmoid(_mem_logit[8][t]->getval()), __fixed_sigmoid(_mem_logit[9][t]->getval()), __fixed_sigmoid(_mem_logit[10][t]->getval()), __fixed_sigmoid(_mem_logit[11][t]->getval()), __fixed_sigmoid(_mem_logit[12][t]->getval()), __fixed_sigmoid(_mem_logit[13][t]->getval()), __fixed_sigmoid(_mem_logit[14][t]->getval()), __fixed_sigmoid(_mem_logit[15][t]->getval()), __fixed_sigmoid(_mem_logit[16][t]->getval()), __fixed_sigmoid(_mem_logit[17][t]->getval()), __fixed_sigmoid(_mem_logit[18][t]->getval()), __fixed_sigmoid(_mem_logit[19][t]->getval()), __fixed_sigmoid(_mem_logit[20][t]->getval()), __fixed_sigmoid(_mem_logit[21][t]->getval()), __fixed_sigmoid(_mem_logit[22][t]->getval()), __fixed_sigmoid(_mem_logit[23][t]->getval()), __fixed_sigmoid(_mem_logit[24][t]->getval()), __fixed_sigmoid(_mem_logit[25][t]->getval()), __fixed_sigmoid(_mem_logit[26][t]->getval()), __fixed_sigmoid(_mem_logit[27][t]->getval()), __fixed_sigmoid(_mem_logit[28][t]->getval()), __fixed_sigmoid(_mem_logit[29][t]->getval()), __fixed_sigmoid(_mem_logit[30][t]->getval()), __fixed_sigmoid(_mem_logit[31][t]->getval()), __fixed_sigmoid(_mem_logit[32][t]->getval()), __fixed_sigmoid(_mem_logit[33][t]->getval()), __fixed_sigmoid(_mem_logit[34][t]->getval()), __fixed_sigmoid(_mem_logit[35][t]->getval()), __fixed_sigmoid(_mem_logit[36][t]->getval()), __fixed_sigmoid(_mem_logit[37][t]->getval()), __fixed_sigmoid(_mem_logit[38][t]->getval()), __fixed_sigmoid(_mem_logit[39][t]->getval()), __fixed_sigmoid(_mem_logit[40][t]->getval()), __fixed_sigmoid(_mem_logit[41][t]->getval()), __fixed_sigmoid(_mem_logit[42][t]->getval()), __fixed_sigmoid(_mem_logit[43][t]->getval()), __fixed_sigmoid(_mem_logit[44][t]->getval()), __fixed_sigmoid(_mem_logit[45][t]->getval()), __fixed_sigmoid(_mem_logit[46][t]->getval()), __fixed_sigmoid(_mem_logit[47][t]->getval()), __fixed_sigmoid(_mem_logit[48][t]->getval()), __fixed_sigmoid(_mem_logit[49][t]->getval()), __fixed_sigmoid(_mem_logit[50][t]->getval()), __fixed_sigmoid(_mem_logit[51][t]->getval()), __fixed_sigmoid(_mem_logit[52][t]->getval()), __fixed_sigmoid(_mem_logit[53][t]->getval()), __fixed_sigmoid(_mem_logit[54][t]->getval()), __fixed_sigmoid(_mem_logit[55][t]->getval()), __fixed_sigmoid(_mem_logit[56][t]->getval()), __fixed_sigmoid(_mem_logit[57][t]->getval()), __fixed_sigmoid(_mem_logit[58][t]->getval()), __fixed_sigmoid(_mem_logit[59][t]->getval()), __fixed_sigmoid(_mem_logit[60][t]->getval()), __fixed_sigmoid(_mem_logit[61][t]->getval()), __fixed_sigmoid(_mem_logit[62][t]->getval()), __fixed_sigmoid(_mem_logit[63][t]->getval()), __fixed_sigmoid(_mem_logit[64][t]->getval()), __fixed_sigmoid(_mem_logit[65][t]->getval()), __fixed_sigmoid(_mem_logit[66][t]->getval()), __fixed_sigmoid(_mem_logit[67][t]->getval()), __fixed_sigmoid(_mem_logit[68][t]->getval()), __fixed_sigmoid(_mem_logit[69][t]->getval()), __fixed_sigmoid(_mem_logit[70][t]->getval()), __fixed_sigmoid(_mem_logit[71][t]->getval()), __fixed_sigmoid(_mem_logit[72][t]->getval()), __fixed_sigmoid(_mem_logit[73][t]->getval()), __fixed_sigmoid(_mem_logit[74][t]->getval()), __fixed_sigmoid(_mem_logit[75][t]->getval()), __fixed_sigmoid(_mem_logit[76][t]->getval()), __fixed_sigmoid(_mem_logit[77][t]->getval()), __fixed_sigmoid(_mem_logit[78][t]->getval()), __fixed_sigmoid(_mem_logit[79][t]->getval()), __fixed_sigmoid(_mem_logit[80][t]->getval()), __fixed_sigmoid(_mem_logit[81][t]->getval()), __fixed_sigmoid(_mem_logit[82][t]->getval()), __fixed_sigmoid(_mem_logit[83][t]->getval()), __fixed_sigmoid(_mem_logit[84][t]->getval()), __fixed_sigmoid(_mem_logit[85][t]->getval()), __fixed_sigmoid(_mem_logit[86][t]->getval()), __fixed_sigmoid(_mem_logit[87][t]->getval()), __fixed_sigmoid(_mem_logit[88][t]->getval()), __fixed_sigmoid(_mem_logit[89][t]->getval()), __fixed_sigmoid(_mem_logit[90][t]->getval()), __fixed_sigmoid(_mem_logit[91][t]->getval()), __fixed_sigmoid(_mem_logit[92][t]->getval()), __fixed_sigmoid(_mem_logit[93][t]->getval()), __fixed_sigmoid(_mem_logit[94][t]->getval()), __fixed_sigmoid(_mem_logit[95][t]->getval()), __fixed_sigmoid(_mem_logit[96][t]->getval()), __fixed_sigmoid(_mem_logit[97][t]->getval()), __fixed_sigmoid(_mem_logit[98][t]->getval()), __fixed_sigmoid(_mem_logit[99][t]->getval()), __fixed_sigmoid(_mem_logit[100][t]->getval()), __fixed_sigmoid(_mem_logit[101][t]->getval()), __fixed_sigmoid(_mem_logit[102][t]->getval()), __fixed_sigmoid(_mem_logit[103][t]->getval()), __fixed_sigmoid(_mem_logit[104][t]->getval()), __fixed_sigmoid(_mem_logit[105][t]->getval()), __fixed_sigmoid(_mem_logit[106][t]->getval()), __fixed_sigmoid(_mem_logit[107][t]->getval()), __fixed_sigmoid(_mem_logit[108][t]->getval()), __fixed_sigmoid(_mem_logit[109][t]->getval()), __fixed_sigmoid(_mem_logit[110][t]->getval()), __fixed_sigmoid(_mem_logit[111][t]->getval()), __fixed_sigmoid(_mem_logit[112][t]->getval()), __fixed_sigmoid(_mem_logit[113][t]->getval()), __fixed_sigmoid(_mem_logit[114][t]->getval()), __fixed_sigmoid(_mem_logit[115][t]->getval()), __fixed_sigmoid(_mem_logit[116][t]->getval()), __fixed_sigmoid(_mem_logit[117][t]->getval()), __fixed_sigmoid(_mem_logit[118][t]->getval()), __fixed_sigmoid(_mem_logit[119][t]->getval()), __fixed_sigmoid(_mem_logit[120][t]->getval()), __fixed_sigmoid(_mem_logit[121][t]->getval()), __fixed_sigmoid(_mem_logit[122][t]->getval()), __fixed_sigmoid(_mem_logit[123][t]->getval()), __fixed_sigmoid(_mem_logit[124][t]->getval()), __fixed_sigmoid(_mem_logit[125][t]->getval()), __fixed_sigmoid(_mem_logit[126][t]->getval()), __fixed_sigmoid(_mem_logit[127][t]->getval()), __fixed_sigmoid(_mem_logit[128][t]->getval()), __fixed_sigmoid(_mem_logit[129][t]->getval()), __fixed_sigmoid(_mem_logit[130][t]->getval()), __fixed_sigmoid(_mem_logit[131][t]->getval()), __fixed_sigmoid(_mem_logit[132][t]->getval()), __fixed_sigmoid(_mem_logit[133][t]->getval()), __fixed_sigmoid(_mem_logit[134][t]->getval()), __fixed_sigmoid(_mem_logit[135][t]->getval()), __fixed_sigmoid(_mem_logit[136][t]->getval()), __fixed_sigmoid(_mem_logit[137][t]->getval()), __fixed_sigmoid(_mem_logit[138][t]->getval()), __fixed_sigmoid(_mem_logit[139][t]->getval()), __fixed_sigmoid(_mem_logit[140][t]->getval()), __fixed_sigmoid(_mem_logit[141][t]->getval()), __fixed_sigmoid(_mem_logit[142][t]->getval()), __fixed_sigmoid(_mem_logit[143][t]->getval()), __fixed_sigmoid(_mem_logit[144][t]->getval()), __fixed_sigmoid(_mem_logit[145][t]->getval()), __fixed_sigmoid(_mem_logit[146][t]->getval()), __fixed_sigmoid(_mem_logit[147][t]->getval()), __fixed_sigmoid(_mem_logit[148][t]->getval()), __fixed_sigmoid(_mem_logit[149][t]->getval()), __fixed_sigmoid(_mem_logit[150][t]->getval()), __fixed_sigmoid(_mem_logit[151][t]->getval()), __fixed_sigmoid(_mem_logit[152][t]->getval()), __fixed_sigmoid(_mem_logit[153][t]->getval()), __fixed_sigmoid(_mem_logit[154][t]->getval()), __fixed_sigmoid(_mem_logit[155][t]->getval()), __fixed_sigmoid(_mem_logit[156][t]->getval()), __fixed_sigmoid(_mem_logit[157][t]->getval()), __fixed_sigmoid(_mem_logit[158][t]->getval()), __fixed_sigmoid(_mem_logit[159][t]->getval()), __fixed_sigmoid(_mem_logit[160][t]->getval()), __fixed_sigmoid(_mem_logit[161][t]->getval()), __fixed_sigmoid(_mem_logit[162][t]->getval()), __fixed_sigmoid(_mem_logit[163][t]->getval()), __fixed_sigmoid(_mem_logit[164][t]->getval()), __fixed_sigmoid(_mem_logit[165][t]->getval()), __fixed_sigmoid(_mem_logit[166][t]->getval()), __fixed_sigmoid(_mem_logit[167][t]->getval()), __fixed_sigmoid(_mem_logit[168][t]->getval()), __fixed_sigmoid(_mem_logit[169][t]->getval()), __fixed_sigmoid(_mem_logit[170][t]->getval()), __fixed_sigmoid(_mem_logit[171][t]->getval()), __fixed_sigmoid(_mem_logit[172][t]->getval()), __fixed_sigmoid(_mem_logit[173][t]->getval()), __fixed_sigmoid(_mem_logit[174][t]->getval()), __fixed_sigmoid(_mem_logit[175][t]->getval()), __fixed_sigmoid(_mem_logit[176][t]->getval()), __fixed_sigmoid(_mem_logit[177][t]->getval()), __fixed_sigmoid(_mem_logit[178][t]->getval()), __fixed_sigmoid(_mem_logit[179][t]->getval()), __fixed_sigmoid(_mem_logit[180][t]->getval()), __fixed_sigmoid(_mem_logit[181][t]->getval()), __fixed_sigmoid(_mem_logit[182][t]->getval()), __fixed_sigmoid(_mem_logit[183][t]->getval()), __fixed_sigmoid(_mem_logit[184][t]->getval()), __fixed_sigmoid(_mem_logit[185][t]->getval()), __fixed_sigmoid(_mem_logit[186][t]->getval()), __fixed_sigmoid(_mem_logit[187][t]->getval()), __fixed_sigmoid(_mem_logit[188][t]->getval()), __fixed_sigmoid(_mem_logit[189][t]->getval()), __fixed_sigmoid(_mem_logit[190][t]->getval()), __fixed_sigmoid(_mem_logit[191][t]->getval()), __fixed_sigmoid(_mem_logit[192][t]->getval()), __fixed_sigmoid(_mem_logit[193][t]->getval()), __fixed_sigmoid(_mem_logit[194][t]->getval()), __fixed_sigmoid(_mem_logit[195][t]->getval()), __fixed_sigmoid(_mem_logit[196][t]->getval()), __fixed_sigmoid(_mem_logit[197][t]->getval()), __fixed_sigmoid(_mem_logit[198][t]->getval()), __fixed_sigmoid(_mem_logit[199][t]->getval()), __fixed_sigmoid(_mem_logit[200][t]->getval()), __fixed_sigmoid(_mem_logit[201][t]->getval()), __fixed_sigmoid(_mem_logit[202][t]->getval()), __fixed_sigmoid(_mem_logit[203][t]->getval()), __fixed_sigmoid(_mem_logit[204][t]->getval()), __fixed_sigmoid(_mem_logit[205][t]->getval()), __fixed_sigmoid(_mem_logit[206][t]->getval()), __fixed_sigmoid(_mem_logit[207][t]->getval()), __fixed_sigmoid(_mem_logit[208][t]->getval()), __fixed_sigmoid(_mem_logit[209][t]->getval()), __fixed_sigmoid(_mem_logit[210][t]->getval()), __fixed_sigmoid(_mem_logit[211][t]->getval()), __fixed_sigmoid(_mem_logit[212][t]->getval()), __fixed_sigmoid(_mem_logit[213][t]->getval()), __fixed_sigmoid(_mem_logit[214][t]->getval()), __fixed_sigmoid(_mem_logit[215][t]->getval()), __fixed_sigmoid(_mem_logit[216][t]->getval()), __fixed_sigmoid(_mem_logit[217][t]->getval()), __fixed_sigmoid(_mem_logit[218][t]->getval()), __fixed_sigmoid(_mem_logit[219][t]->getval()), __fixed_sigmoid(_mem_logit[220][t]->getval()), __fixed_sigmoid(_mem_logit[221][t]->getval()), __fixed_sigmoid(_mem_logit[222][t]->getval()), __fixed_sigmoid(_mem_logit[223][t]->getval()), __fixed_sigmoid(_mem_logit[224][t]->getval()), __fixed_sigmoid(_mem_logit[225][t]->getval()), __fixed_sigmoid(_mem_logit[226][t]->getval()), __fixed_sigmoid(_mem_logit[227][t]->getval()), __fixed_sigmoid(_mem_logit[228][t]->getval()), __fixed_sigmoid(_mem_logit[229][t]->getval()), __fixed_sigmoid(_mem_logit[230][t]->getval()), __fixed_sigmoid(_mem_logit[231][t]->getval()), __fixed_sigmoid(_mem_logit[232][t]->getval()), __fixed_sigmoid(_mem_logit[233][t]->getval()), __fixed_sigmoid(_mem_logit[234][t]->getval()), __fixed_sigmoid(_mem_logit[235][t]->getval()), __fixed_sigmoid(_mem_logit[236][t]->getval()), __fixed_sigmoid(_mem_logit[237][t]->getval()), __fixed_sigmoid(_mem_logit[238][t]->getval()), __fixed_sigmoid(_mem_logit[239][t]->getval()), __fixed_sigmoid(_mem_logit[240][t]->getval()), __fixed_sigmoid(_mem_logit[241][t]->getval()), __fixed_sigmoid(_mem_logit[242][t]->getval()), __fixed_sigmoid(_mem_logit[243][t]->getval()), __fixed_sigmoid(_mem_logit[244][t]->getval()), __fixed_sigmoid(_mem_logit[245][t]->getval()), __fixed_sigmoid(_mem_logit[246][t]->getval()), __fixed_sigmoid(_mem_logit[247][t]->getval()), __fixed_sigmoid(_mem_logit[248][t]->getval()), __fixed_sigmoid(_mem_logit[249][t]->getval()), __fixed_sigmoid(_mem_logit[250][t]->getval()), __fixed_sigmoid(_mem_logit[251][t]->getval()), __fixed_sigmoid(_mem_logit[252][t]->getval()), __fixed_sigmoid(_mem_logit[253][t]->getval()), __fixed_sigmoid(_mem_logit[254][t]->getval()), __fixed_sigmoid(_mem_logit[255][t]->getval()), __fixed_sigmoid(_mem_logit[256][t]->getval()), __fixed_sigmoid(_mem_logit[257][t]->getval()), __fixed_sigmoid(_mem_logit[258][t]->getval()), __fixed_sigmoid(_mem_logit[259][t]->getval()), __fixed_sigmoid(_mem_logit[260][t]->getval()), __fixed_sigmoid(_mem_logit[261][t]->getval()), __fixed_sigmoid(_mem_logit[262][t]->getval()), __fixed_sigmoid(_mem_logit[263][t]->getval()), __fixed_sigmoid(_mem_logit[264][t]->getval()), __fixed_sigmoid(_mem_logit[265][t]->getval()), __fixed_sigmoid(_mem_logit[266][t]->getval()), __fixed_sigmoid(_mem_logit[267][t]->getval()), __fixed_sigmoid(_mem_logit[268][t]->getval()), __fixed_sigmoid(_mem_logit[269][t]->getval()), __fixed_sigmoid(_mem_logit[270][t]->getval()), __fixed_sigmoid(_mem_logit[271][t]->getval()), __fixed_sigmoid(_mem_logit[272][t]->getval()), __fixed_sigmoid(_mem_logit[273][t]->getval()), __fixed_sigmoid(_mem_logit[274][t]->getval()), __fixed_sigmoid(_mem_logit[275][t]->getval()), __fixed_sigmoid(_mem_logit[276][t]->getval())}))/__fixed_region_pop[r],0.00500000),Gaussian28870544.loglikeli(val);
}
double _Var_region_rate::getcachelikeli()
{
  auto _t_val = getcache();
  return Gaussian28870544.init(dot(__fixed_county_map.row(r),vstack({__fixed_sigmoid(_mem_logit[0][t]->getcache()), __fixed_sigmoid(_mem_logit[1][t]->getcache()), __fixed_sigmoid(_mem_logit[2][t]->getcache()), __fixed_sigmoid(_mem_logit[3][t]->getcache()), __fixed_sigmoid(_mem_logit[4][t]->getcache()), __fixed_sigmoid(_mem_logit[5][t]->getcache()), __fixed_sigmoid(_mem_logit[6][t]->getcache()), __fixed_sigmoid(_mem_logit[7][t]->getcache()), __fixed_sigmoid(_mem_logit[8][t]->getcache()), __fixed_sigmoid(_mem_logit[9][t]->getcache()), __fixed_sigmoid(_mem_logit[10][t]->getcache()), __fixed_sigmoid(_mem_logit[11][t]->getcache()), __fixed_sigmoid(_mem_logit[12][t]->getcache()), __fixed_sigmoid(_mem_logit[13][t]->getcache()), __fixed_sigmoid(_mem_logit[14][t]->getcache()), __fixed_sigmoid(_mem_logit[15][t]->getcache()), __fixed_sigmoid(_mem_logit[16][t]->getcache()), __fixed_sigmoid(_mem_logit[17][t]->getcache()), __fixed_sigmoid(_mem_logit[18][t]->getcache()), __fixed_sigmoid(_mem_logit[19][t]->getcache()), __fixed_sigmoid(_mem_logit[20][t]->getcache()), __fixed_sigmoid(_mem_logit[21][t]->getcache()), __fixed_sigmoid(_mem_logit[22][t]->getcache()), __fixed_sigmoid(_mem_logit[23][t]->getcache()), __fixed_sigmoid(_mem_logit[24][t]->getcache()), __fixed_sigmoid(_mem_logit[25][t]->getcache()), __fixed_sigmoid(_mem_logit[26][t]->getcache()), __fixed_sigmoid(_mem_logit[27][t]->getcache()), __fixed_sigmoid(_mem_logit[28][t]->getcache()), __fixed_sigmoid(_mem_logit[29][t]->getcache()), __fixed_sigmoid(_mem_logit[30][t]->getcache()), __fixed_sigmoid(_mem_logit[31][t]->getcache()), __fixed_sigmoid(_mem_logit[32][t]->getcache()), __fixed_sigmoid(_mem_logit[33][t]->getcache()), __fixed_sigmoid(_mem_logit[34][t]->getcache()), __fixed_sigmoid(_mem_logit[35][t]->getcache()), __fixed_sigmoid(_mem_logit[36][t]->getcache()), __fixed_sigmoid(_mem_logit[37][t]->getcache()), __fixed_sigmoid(_mem_logit[38][t]->getcache()), __fixed_sigmoid(_mem_logit[39][t]->getcache()), __fixed_sigmoid(_mem_logit[40][t]->getcache()), __fixed_sigmoid(_mem_logit[41][t]->getcache()), __fixed_sigmoid(_mem_logit[42][t]->getcache()), __fixed_sigmoid(_mem_logit[43][t]->getcache()), __fixed_sigmoid(_mem_logit[44][t]->getcache()), __fixed_sigmoid(_mem_logit[45][t]->getcache()), __fixed_sigmoid(_mem_logit[46][t]->getcache()), __fixed_sigmoid(_mem_logit[47][t]->getcache()), __fixed_sigmoid(_mem_logit[48][t]->getcache()), __fixed_sigmoid(_mem_logit[49][t]->getcache()), __fixed_sigmoid(_mem_logit[50][t]->getcache()), __fixed_sigmoid(_mem_logit[51][t]->getcache()), __fixed_sigmoid(_mem_logit[52][t]->getcache()), __fixed_sigmoid(_mem_logit[53][t]->getcache()), __fixed_sigmoid(_mem_logit[54][t]->getcache()), __fixed_sigmoid(_mem_logit[55][t]->getcache()), __fixed_sigmoid(_mem_logit[56][t]->getcache()), __fixed_sigmoid(_mem_logit[57][t]->getcache()), __fixed_sigmoid(_mem_logit[58][t]->getcache()), __fixed_sigmoid(_mem_logit[59][t]->getcache()), __fixed_sigmoid(_mem_logit[60][t]->getcache()), __fixed_sigmoid(_mem_logit[61][t]->getcache()), __fixed_sigmoid(_mem_logit[62][t]->getcache()), __fixed_sigmoid(_mem_logit[63][t]->getcache()), __fixed_sigmoid(_mem_logit[64][t]->getcache()), __fixed_sigmoid(_mem_logit[65][t]->getcache()), __fixed_sigmoid(_mem_logit[66][t]->getcache()), __fixed_sigmoid(_mem_logit[67][t]->getcache()), __fixed_sigmoid(_mem_logit[68][t]->getcache()), __fixed_sigmoid(_mem_logit[69][t]->getcache()), __fixed_sigmoid(_mem_logit[70][t]->getcache()), __fixed_sigmoid(_mem_logit[71][t]->getcache()), __fixed_sigmoid(_mem_logit[72][t]->getcache()), __fixed_sigmoid(_mem_logit[73][t]->getcache()), __fixed_sigmoid(_mem_logit[74][t]->getcache()), __fixed_sigmoid(_mem_logit[75][t]->getcache()), __fixed_sigmoid(_mem_logit[76][t]->getcache()), __fixed_sigmoid(_mem_logit[77][t]->getcache()), __fixed_sigmoid(_mem_logit[78][t]->getcache()), __fixed_sigmoid(_mem_logit[79][t]->getcache()), __fixed_sigmoid(_mem_logit[80][t]->getcache()), __fixed_sigmoid(_mem_logit[81][t]->getcache()), __fixed_sigmoid(_mem_logit[82][t]->getcache()), __fixed_sigmoid(_mem_logit[83][t]->getcache()), __fixed_sigmoid(_mem_logit[84][t]->getcache()), __fixed_sigmoid(_mem_logit[85][t]->getcache()), __fixed_sigmoid(_mem_logit[86][t]->getcache()), __fixed_sigmoid(_mem_logit[87][t]->getcache()), __fixed_sigmoid(_mem_logit[88][t]->getcache()), __fixed_sigmoid(_mem_logit[89][t]->getcache()), __fixed_sigmoid(_mem_logit[90][t]->getcache()), __fixed_sigmoid(_mem_logit[91][t]->getcache()), __fixed_sigmoid(_mem_logit[92][t]->getcache()), __fixed_sigmoid(_mem_logit[93][t]->getcache()), __fixed_sigmoid(_mem_logit[94][t]->getcache()), __fixed_sigmoid(_mem_logit[95][t]->getcache()), __fixed_sigmoid(_mem_logit[96][t]->getcache()), __fixed_sigmoid(_mem_logit[97][t]->getcache()), __fixed_sigmoid(_mem_logit[98][t]->getcache()), __fixed_sigmoid(_mem_logit[99][t]->getcache()), __fixed_sigmoid(_mem_logit[100][t]->getcache()), __fixed_sigmoid(_mem_logit[101][t]->getcache()), __fixed_sigmoid(_mem_logit[102][t]->getcache()), __fixed_sigmoid(_mem_logit[103][t]->getcache()), __fixed_sigmoid(_mem_logit[104][t]->getcache()), __fixed_sigmoid(_mem_logit[105][t]->getcache()), __fixed_sigmoid(_mem_logit[106][t]->getcache()), __fixed_sigmoid(_mem_logit[107][t]->getcache()), __fixed_sigmoid(_mem_logit[108][t]->getcache()), __fixed_sigmoid(_mem_logit[109][t]->getcache()), __fixed_sigmoid(_mem_logit[110][t]->getcache()), __fixed_sigmoid(_mem_logit[111][t]->getcache()), __fixed_sigmoid(_mem_logit[112][t]->getcache()), __fixed_sigmoid(_mem_logit[113][t]->getcache()), __fixed_sigmoid(_mem_logit[114][t]->getcache()), __fixed_sigmoid(_mem_logit[115][t]->getcache()), __fixed_sigmoid(_mem_logit[116][t]->getcache()), __fixed_sigmoid(_mem_logit[117][t]->getcache()), __fixed_sigmoid(_mem_logit[118][t]->getcache()), __fixed_sigmoid(_mem_logit[119][t]->getcache()), __fixed_sigmoid(_mem_logit[120][t]->getcache()), __fixed_sigmoid(_mem_logit[121][t]->getcache()), __fixed_sigmoid(_mem_logit[122][t]->getcache()), __fixed_sigmoid(_mem_logit[123][t]->getcache()), __fixed_sigmoid(_mem_logit[124][t]->getcache()), __fixed_sigmoid(_mem_logit[125][t]->getcache()), __fixed_sigmoid(_mem_logit[126][t]->getcache()), __fixed_sigmoid(_mem_logit[127][t]->getcache()), __fixed_sigmoid(_mem_logit[128][t]->getcache()), __fixed_sigmoid(_mem_logit[129][t]->getcache()), __fixed_sigmoid(_mem_logit[130][t]->getcache()), __fixed_sigmoid(_mem_logit[131][t]->getcache()), __fixed_sigmoid(_mem_logit[132][t]->getcache()), __fixed_sigmoid(_mem_logit[133][t]->getcache()), __fixed_sigmoid(_mem_logit[134][t]->getcache()), __fixed_sigmoid(_mem_logit[135][t]->getcache()), __fixed_sigmoid(_mem_logit[136][t]->getcache()), __fixed_sigmoid(_mem_logit[137][t]->getcache()), __fixed_sigmoid(_mem_logit[138][t]->getcache()), __fixed_sigmoid(_mem_logit[139][t]->getcache()), __fixed_sigmoid(_mem_logit[140][t]->getcache()), __fixed_sigmoid(_mem_logit[141][t]->getcache()), __fixed_sigmoid(_mem_logit[142][t]->getcache()), __fixed_sigmoid(_mem_logit[143][t]->getcache()), __fixed_sigmoid(_mem_logit[144][t]->getcache()), __fixed_sigmoid(_mem_logit[145][t]->getcache()), __fixed_sigmoid(_mem_logit[146][t]->getcache()), __fixed_sigmoid(_mem_logit[147][t]->getcache()), __fixed_sigmoid(_mem_logit[148][t]->getcache()), __fixed_sigmoid(_mem_logit[149][t]->getcache()), __fixed_sigmoid(_mem_logit[150][t]->getcache()), __fixed_sigmoid(_mem_logit[151][t]->getcache()), __fixed_sigmoid(_mem_logit[152][t]->getcache()), __fixed_sigmoid(_mem_logit[153][t]->getcache()), __fixed_sigmoid(_mem_logit[154][t]->getcache()), __fixed_sigmoid(_mem_logit[155][t]->getcache()), __fixed_sigmoid(_mem_logit[156][t]->getcache()), __fixed_sigmoid(_mem_logit[157][t]->getcache()), __fixed_sigmoid(_mem_logit[158][t]->getcache()), __fixed_sigmoid(_mem_logit[159][t]->getcache()), __fixed_sigmoid(_mem_logit[160][t]->getcache()), __fixed_sigmoid(_mem_logit[161][t]->getcache()), __fixed_sigmoid(_mem_logit[162][t]->getcache()), __fixed_sigmoid(_mem_logit[163][t]->getcache()), __fixed_sigmoid(_mem_logit[164][t]->getcache()), __fixed_sigmoid(_mem_logit[165][t]->getcache()), __fixed_sigmoid(_mem_logit[166][t]->getcache()), __fixed_sigmoid(_mem_logit[167][t]->getcache()), __fixed_sigmoid(_mem_logit[168][t]->getcache()), __fixed_sigmoid(_mem_logit[169][t]->getcache()), __fixed_sigmoid(_mem_logit[170][t]->getcache()), __fixed_sigmoid(_mem_logit[171][t]->getcache()), __fixed_sigmoid(_mem_logit[172][t]->getcache()), __fixed_sigmoid(_mem_logit[173][t]->getcache()), __fixed_sigmoid(_mem_logit[174][t]->getcache()), __fixed_sigmoid(_mem_logit[175][t]->getcache()), __fixed_sigmoid(_mem_logit[176][t]->getcache()), __fixed_sigmoid(_mem_logit[177][t]->getcache()), __fixed_sigmoid(_mem_logit[178][t]->getcache()), __fixed_sigmoid(_mem_logit[179][t]->getcache()), __fixed_sigmoid(_mem_logit[180][t]->getcache()), __fixed_sigmoid(_mem_logit[181][t]->getcache()), __fixed_sigmoid(_mem_logit[182][t]->getcache()), __fixed_sigmoid(_mem_logit[183][t]->getcache()), __fixed_sigmoid(_mem_logit[184][t]->getcache()), __fixed_sigmoid(_mem_logit[185][t]->getcache()), __fixed_sigmoid(_mem_logit[186][t]->getcache()), __fixed_sigmoid(_mem_logit[187][t]->getcache()), __fixed_sigmoid(_mem_logit[188][t]->getcache()), __fixed_sigmoid(_mem_logit[189][t]->getcache()), __fixed_sigmoid(_mem_logit[190][t]->getcache()), __fixed_sigmoid(_mem_logit[191][t]->getcache()), __fixed_sigmoid(_mem_logit[192][t]->getcache()), __fixed_sigmoid(_mem_logit[193][t]->getcache()), __fixed_sigmoid(_mem_logit[194][t]->getcache()), __fixed_sigmoid(_mem_logit[195][t]->getcache()), __fixed_sigmoid(_mem_logit[196][t]->getcache()), __fixed_sigmoid(_mem_logit[197][t]->getcache()), __fixed_sigmoid(_mem_logit[198][t]->getcache()), __fixed_sigmoid(_mem_logit[199][t]->getcache()), __fixed_sigmoid(_mem_logit[200][t]->getcache()), __fixed_sigmoid(_mem_logit[201][t]->getcache()), __fixed_sigmoid(_mem_logit[202][t]->getcache()), __fixed_sigmoid(_mem_logit[203][t]->getcache()), __fixed_sigmoid(_mem_logit[204][t]->getcache()), __fixed_sigmoid(_mem_logit[205][t]->getcache()), __fixed_sigmoid(_mem_logit[206][t]->getcache()), __fixed_sigmoid(_mem_logit[207][t]->getcache()), __fixed_sigmoid(_mem_logit[208][t]->getcache()), __fixed_sigmoid(_mem_logit[209][t]->getcache()), __fixed_sigmoid(_mem_logit[210][t]->getcache()), __fixed_sigmoid(_mem_logit[211][t]->getcache()), __fixed_sigmoid(_mem_logit[212][t]->getcache()), __fixed_sigmoid(_mem_logit[213][t]->getcache()), __fixed_sigmoid(_mem_logit[214][t]->getcache()), __fixed_sigmoid(_mem_logit[215][t]->getcache()), __fixed_sigmoid(_mem_logit[216][t]->getcache()), __fixed_sigmoid(_mem_logit[217][t]->getcache()), __fixed_sigmoid(_mem_logit[218][t]->getcache()), __fixed_sigmoid(_mem_logit[219][t]->getcache()), __fixed_sigmoid(_mem_logit[220][t]->getcache()), __fixed_sigmoid(_mem_logit[221][t]->getcache()), __fixed_sigmoid(_mem_logit[222][t]->getcache()), __fixed_sigmoid(_mem_logit[223][t]->getcache()), __fixed_sigmoid(_mem_logit[224][t]->getcache()), __fixed_sigmoid(_mem_logit[225][t]->getcache()), __fixed_sigmoid(_mem_logit[226][t]->getcache()), __fixed_sigmoid(_mem_logit[227][t]->getcache()), __fixed_sigmoid(_mem_logit[228][t]->getcache()), __fixed_sigmoid(_mem_logit[229][t]->getcache()), __fixed_sigmoid(_mem_logit[230][t]->getcache()), __fixed_sigmoid(_mem_logit[231][t]->getcache()), __fixed_sigmoid(_mem_logit[232][t]->getcache()), __fixed_sigmoid(_mem_logit[233][t]->getcache()), __fixed_sigmoid(_mem_logit[234][t]->getcache()), __fixed_sigmoid(_mem_logit[235][t]->getcache()), __fixed_sigmoid(_mem_logit[236][t]->getcache()), __fixed_sigmoid(_mem_logit[237][t]->getcache()), __fixed_sigmoid(_mem_logit[238][t]->getcache()), __fixed_sigmoid(_mem_logit[239][t]->getcache()), __fixed_sigmoid(_mem_logit[240][t]->getcache()), __fixed_sigmoid(_mem_logit[241][t]->getcache()), __fixed_sigmoid(_mem_logit[242][t]->getcache()), __fixed_sigmoid(_mem_logit[243][t]->getcache()), __fixed_sigmoid(_mem_logit[244][t]->getcache()), __fixed_sigmoid(_mem_logit[245][t]->getcache()), __fixed_sigmoid(_mem_logit[246][t]->getcache()), __fixed_sigmoid(_mem_logit[247][t]->getcache()), __fixed_sigmoid(_mem_logit[248][t]->getcache()), __fixed_sigmoid(_mem_logit[249][t]->getcache()), __fixed_sigmoid(_mem_logit[250][t]->getcache()), __fixed_sigmoid(_mem_logit[251][t]->getcache()), __fixed_sigmoid(_mem_logit[252][t]->getcache()), __fixed_sigmoid(_mem_logit[253][t]->getcache()), __fixed_sigmoid(_mem_logit[254][t]->getcache()), __fixed_sigmoid(_mem_logit[255][t]->getcache()), __fixed_sigmoid(_mem_logit[256][t]->getcache()), __fixed_sigmoid(_mem_logit[257][t]->getcache()), __fixed_sigmoid(_mem_logit[258][t]->getcache()), __fixed_sigmoid(_mem_logit[259][t]->getcache()), __fixed_sigmoid(_mem_logit[260][t]->getcache()), __fixed_sigmoid(_mem_logit[261][t]->getcache()), __fixed_sigmoid(_mem_logit[262][t]->getcache()), __fixed_sigmoid(_mem_logit[263][t]->getcache()), __fixed_sigmoid(_mem_logit[264][t]->getcache()), __fixed_sigmoid(_mem_logit[265][t]->getcache()), __fixed_sigmoid(_mem_logit[266][t]->getcache()), __fixed_sigmoid(_mem_logit[267][t]->getcache()), __fixed_sigmoid(_mem_logit[268][t]->getcache()), __fixed_sigmoid(_mem_logit[269][t]->getcache()), __fixed_sigmoid(_mem_logit[270][t]->getcache()), __fixed_sigmoid(_mem_logit[271][t]->getcache()), __fixed_sigmoid(_mem_logit[272][t]->getcache()), __fixed_sigmoid(_mem_logit[273][t]->getcache()), __fixed_sigmoid(_mem_logit[274][t]->getcache()), __fixed_sigmoid(_mem_logit[275][t]->getcache()), __fixed_sigmoid(_mem_logit[276][t]->getcache())}))/__fixed_region_pop[r],0.00500000),Gaussian28870544.loglikeli(_t_val);
}
void _Var_region_rate::sample()
{
  val=(Gaussian28870544.init(dot(__fixed_county_map.row(r),vstack({__fixed_sigmoid(_mem_logit[0][t]->getval()), __fixed_sigmoid(_mem_logit[1][t]->getval()), __fixed_sigmoid(_mem_logit[2][t]->getval()), __fixed_sigmoid(_mem_logit[3][t]->getval()), __fixed_sigmoid(_mem_logit[4][t]->getval()), __fixed_sigmoid(_mem_logit[5][t]->getval()), __fixed_sigmoid(_mem_logit[6][t]->getval()), __fixed_sigmoid(_mem_logit[7][t]->getval()), __fixed_sigmoid(_mem_logit[8][t]->getval()), __fixed_sigmoid(_mem_logit[9][t]->getval()), __fixed_sigmoid(_mem_logit[10][t]->getval()), __fixed_sigmoid(_mem_logit[11][t]->getval()), __fixed_sigmoid(_mem_logit[12][t]->getval()), __fixed_sigmoid(_mem_logit[13][t]->getval()), __fixed_sigmoid(_mem_logit[14][t]->getval()), __fixed_sigmoid(_mem_logit[15][t]->getval()), __fixed_sigmoid(_mem_logit[16][t]->getval()), __fixed_sigmoid(_mem_logit[17][t]->getval()), __fixed_sigmoid(_mem_logit[18][t]->getval()), __fixed_sigmoid(_mem_logit[19][t]->getval()), __fixed_sigmoid(_mem_logit[20][t]->getval()), __fixed_sigmoid(_mem_logit[21][t]->getval()), __fixed_sigmoid(_mem_logit[22][t]->getval()), __fixed_sigmoid(_mem_logit[23][t]->getval()), __fixed_sigmoid(_mem_logit[24][t]->getval()), __fixed_sigmoid(_mem_logit[25][t]->getval()), __fixed_sigmoid(_mem_logit[26][t]->getval()), __fixed_sigmoid(_mem_logit[27][t]->getval()), __fixed_sigmoid(_mem_logit[28][t]->getval()), __fixed_sigmoid(_mem_logit[29][t]->getval()), __fixed_sigmoid(_mem_logit[30][t]->getval()), __fixed_sigmoid(_mem_logit[31][t]->getval()), __fixed_sigmoid(_mem_logit[32][t]->getval()), __fixed_sigmoid(_mem_logit[33][t]->getval()), __fixed_sigmoid(_mem_logit[34][t]->getval()), __fixed_sigmoid(_mem_logit[35][t]->getval()), __fixed_sigmoid(_mem_logit[36][t]->getval()), __fixed_sigmoid(_mem_logit[37][t]->getval()), __fixed_sigmoid(_mem_logit[38][t]->getval()), __fixed_sigmoid(_mem_logit[39][t]->getval()), __fixed_sigmoid(_mem_logit[40][t]->getval()), __fixed_sigmoid(_mem_logit[41][t]->getval()), __fixed_sigmoid(_mem_logit[42][t]->getval()), __fixed_sigmoid(_mem_logit[43][t]->getval()), __fixed_sigmoid(_mem_logit[44][t]->getval()), __fixed_sigmoid(_mem_logit[45][t]->getval()), __fixed_sigmoid(_mem_logit[46][t]->getval()), __fixed_sigmoid(_mem_logit[47][t]->getval()), __fixed_sigmoid(_mem_logit[48][t]->getval()), __fixed_sigmoid(_mem_logit[49][t]->getval()), __fixed_sigmoid(_mem_logit[50][t]->getval()), __fixed_sigmoid(_mem_logit[51][t]->getval()), __fixed_sigmoid(_mem_logit[52][t]->getval()), __fixed_sigmoid(_mem_logit[53][t]->getval()), __fixed_sigmoid(_mem_logit[54][t]->getval()), __fixed_sigmoid(_mem_logit[55][t]->getval()), __fixed_sigmoid(_mem_logit[56][t]->getval()), __fixed_sigmoid(_mem_logit[57][t]->getval()), __fixed_sigmoid(_mem_logit[58][t]->getval()), __fixed_sigmoid(_mem_logit[59][t]->getval()), __fixed_sigmoid(_mem_logit[60][t]->getval()), __fixed_sigmoid(_mem_logit[61][t]->getval()), __fixed_sigmoid(_mem_logit[62][t]->getval()), __fixed_sigmoid(_mem_logit[63][t]->getval()), __fixed_sigmoid(_mem_logit[64][t]->getval()), __fixed_sigmoid(_mem_logit[65][t]->getval()), __fixed_sigmoid(_mem_logit[66][t]->getval()), __fixed_sigmoid(_mem_logit[67][t]->getval()), __fixed_sigmoid(_mem_logit[68][t]->getval()), __fixed_sigmoid(_mem_logit[69][t]->getval()), __fixed_sigmoid(_mem_logit[70][t]->getval()), __fixed_sigmoid(_mem_logit[71][t]->getval()), __fixed_sigmoid(_mem_logit[72][t]->getval()), __fixed_sigmoid(_mem_logit[73][t]->getval()), __fixed_sigmoid(_mem_logit[74][t]->getval()), __fixed_sigmoid(_mem_logit[75][t]->getval()), __fixed_sigmoid(_mem_logit[76][t]->getval()), __fixed_sigmoid(_mem_logit[77][t]->getval()), __fixed_sigmoid(_mem_logit[78][t]->getval()), __fixed_sigmoid(_mem_logit[79][t]->getval()), __fixed_sigmoid(_mem_logit[80][t]->getval()), __fixed_sigmoid(_mem_logit[81][t]->getval()), __fixed_sigmoid(_mem_logit[82][t]->getval()), __fixed_sigmoid(_mem_logit[83][t]->getval()), __fixed_sigmoid(_mem_logit[84][t]->getval()), __fixed_sigmoid(_mem_logit[85][t]->getval()), __fixed_sigmoid(_mem_logit[86][t]->getval()), __fixed_sigmoid(_mem_logit[87][t]->getval()), __fixed_sigmoid(_mem_logit[88][t]->getval()), __fixed_sigmoid(_mem_logit[89][t]->getval()), __fixed_sigmoid(_mem_logit[90][t]->getval()), __fixed_sigmoid(_mem_logit[91][t]->getval()), __fixed_sigmoid(_mem_logit[92][t]->getval()), __fixed_sigmoid(_mem_logit[93][t]->getval()), __fixed_sigmoid(_mem_logit[94][t]->getval()), __fixed_sigmoid(_mem_logit[95][t]->getval()), __fixed_sigmoid(_mem_logit[96][t]->getval()), __fixed_sigmoid(_mem_logit[97][t]->getval()), __fixed_sigmoid(_mem_logit[98][t]->getval()), __fixed_sigmoid(_mem_logit[99][t]->getval()), __fixed_sigmoid(_mem_logit[100][t]->getval()), __fixed_sigmoid(_mem_logit[101][t]->getval()), __fixed_sigmoid(_mem_logit[102][t]->getval()), __fixed_sigmoid(_mem_logit[103][t]->getval()), __fixed_sigmoid(_mem_logit[104][t]->getval()), __fixed_sigmoid(_mem_logit[105][t]->getval()), __fixed_sigmoid(_mem_logit[106][t]->getval()), __fixed_sigmoid(_mem_logit[107][t]->getval()), __fixed_sigmoid(_mem_logit[108][t]->getval()), __fixed_sigmoid(_mem_logit[109][t]->getval()), __fixed_sigmoid(_mem_logit[110][t]->getval()), __fixed_sigmoid(_mem_logit[111][t]->getval()), __fixed_sigmoid(_mem_logit[112][t]->getval()), __fixed_sigmoid(_mem_logit[113][t]->getval()), __fixed_sigmoid(_mem_logit[114][t]->getval()), __fixed_sigmoid(_mem_logit[115][t]->getval()), __fixed_sigmoid(_mem_logit[116][t]->getval()), __fixed_sigmoid(_mem_logit[117][t]->getval()), __fixed_sigmoid(_mem_logit[118][t]->getval()), __fixed_sigmoid(_mem_logit[119][t]->getval()), __fixed_sigmoid(_mem_logit[120][t]->getval()), __fixed_sigmoid(_mem_logit[121][t]->getval()), __fixed_sigmoid(_mem_logit[122][t]->getval()), __fixed_sigmoid(_mem_logit[123][t]->getval()), __fixed_sigmoid(_mem_logit[124][t]->getval()), __fixed_sigmoid(_mem_logit[125][t]->getval()), __fixed_sigmoid(_mem_logit[126][t]->getval()), __fixed_sigmoid(_mem_logit[127][t]->getval()), __fixed_sigmoid(_mem_logit[128][t]->getval()), __fixed_sigmoid(_mem_logit[129][t]->getval()), __fixed_sigmoid(_mem_logit[130][t]->getval()), __fixed_sigmoid(_mem_logit[131][t]->getval()), __fixed_sigmoid(_mem_logit[132][t]->getval()), __fixed_sigmoid(_mem_logit[133][t]->getval()), __fixed_sigmoid(_mem_logit[134][t]->getval()), __fixed_sigmoid(_mem_logit[135][t]->getval()), __fixed_sigmoid(_mem_logit[136][t]->getval()), __fixed_sigmoid(_mem_logit[137][t]->getval()), __fixed_sigmoid(_mem_logit[138][t]->getval()), __fixed_sigmoid(_mem_logit[139][t]->getval()), __fixed_sigmoid(_mem_logit[140][t]->getval()), __fixed_sigmoid(_mem_logit[141][t]->getval()), __fixed_sigmoid(_mem_logit[142][t]->getval()), __fixed_sigmoid(_mem_logit[143][t]->getval()), __fixed_sigmoid(_mem_logit[144][t]->getval()), __fixed_sigmoid(_mem_logit[145][t]->getval()), __fixed_sigmoid(_mem_logit[146][t]->getval()), __fixed_sigmoid(_mem_logit[147][t]->getval()), __fixed_sigmoid(_mem_logit[148][t]->getval()), __fixed_sigmoid(_mem_logit[149][t]->getval()), __fixed_sigmoid(_mem_logit[150][t]->getval()), __fixed_sigmoid(_mem_logit[151][t]->getval()), __fixed_sigmoid(_mem_logit[152][t]->getval()), __fixed_sigmoid(_mem_logit[153][t]->getval()), __fixed_sigmoid(_mem_logit[154][t]->getval()), __fixed_sigmoid(_mem_logit[155][t]->getval()), __fixed_sigmoid(_mem_logit[156][t]->getval()), __fixed_sigmoid(_mem_logit[157][t]->getval()), __fixed_sigmoid(_mem_logit[158][t]->getval()), __fixed_sigmoid(_mem_logit[159][t]->getval()), __fixed_sigmoid(_mem_logit[160][t]->getval()), __fixed_sigmoid(_mem_logit[161][t]->getval()), __fixed_sigmoid(_mem_logit[162][t]->getval()), __fixed_sigmoid(_mem_logit[163][t]->getval()), __fixed_sigmoid(_mem_logit[164][t]->getval()), __fixed_sigmoid(_mem_logit[165][t]->getval()), __fixed_sigmoid(_mem_logit[166][t]->getval()), __fixed_sigmoid(_mem_logit[167][t]->getval()), __fixed_sigmoid(_mem_logit[168][t]->getval()), __fixed_sigmoid(_mem_logit[169][t]->getval()), __fixed_sigmoid(_mem_logit[170][t]->getval()), __fixed_sigmoid(_mem_logit[171][t]->getval()), __fixed_sigmoid(_mem_logit[172][t]->getval()), __fixed_sigmoid(_mem_logit[173][t]->getval()), __fixed_sigmoid(_mem_logit[174][t]->getval()), __fixed_sigmoid(_mem_logit[175][t]->getval()), __fixed_sigmoid(_mem_logit[176][t]->getval()), __fixed_sigmoid(_mem_logit[177][t]->getval()), __fixed_sigmoid(_mem_logit[178][t]->getval()), __fixed_sigmoid(_mem_logit[179][t]->getval()), __fixed_sigmoid(_mem_logit[180][t]->getval()), __fixed_sigmoid(_mem_logit[181][t]->getval()), __fixed_sigmoid(_mem_logit[182][t]->getval()), __fixed_sigmoid(_mem_logit[183][t]->getval()), __fixed_sigmoid(_mem_logit[184][t]->getval()), __fixed_sigmoid(_mem_logit[185][t]->getval()), __fixed_sigmoid(_mem_logit[186][t]->getval()), __fixed_sigmoid(_mem_logit[187][t]->getval()), __fixed_sigmoid(_mem_logit[188][t]->getval()), __fixed_sigmoid(_mem_logit[189][t]->getval()), __fixed_sigmoid(_mem_logit[190][t]->getval()), __fixed_sigmoid(_mem_logit[191][t]->getval()), __fixed_sigmoid(_mem_logit[192][t]->getval()), __fixed_sigmoid(_mem_logit[193][t]->getval()), __fixed_sigmoid(_mem_logit[194][t]->getval()), __fixed_sigmoid(_mem_logit[195][t]->getval()), __fixed_sigmoid(_mem_logit[196][t]->getval()), __fixed_sigmoid(_mem_logit[197][t]->getval()), __fixed_sigmoid(_mem_logit[198][t]->getval()), __fixed_sigmoid(_mem_logit[199][t]->getval()), __fixed_sigmoid(_mem_logit[200][t]->getval()), __fixed_sigmoid(_mem_logit[201][t]->getval()), __fixed_sigmoid(_mem_logit[202][t]->getval()), __fixed_sigmoid(_mem_logit[203][t]->getval()), __fixed_sigmoid(_mem_logit[204][t]->getval()), __fixed_sigmoid(_mem_logit[205][t]->getval()), __fixed_sigmoid(_mem_logit[206][t]->getval()), __fixed_sigmoid(_mem_logit[207][t]->getval()), __fixed_sigmoid(_mem_logit[208][t]->getval()), __fixed_sigmoid(_mem_logit[209][t]->getval()), __fixed_sigmoid(_mem_logit[210][t]->getval()), __fixed_sigmoid(_mem_logit[211][t]->getval()), __fixed_sigmoid(_mem_logit[212][t]->getval()), __fixed_sigmoid(_mem_logit[213][t]->getval()), __fixed_sigmoid(_mem_logit[214][t]->getval()), __fixed_sigmoid(_mem_logit[215][t]->getval()), __fixed_sigmoid(_mem_logit[216][t]->getval()), __fixed_sigmoid(_mem_logit[217][t]->getval()), __fixed_sigmoid(_mem_logit[218][t]->getval()), __fixed_sigmoid(_mem_logit[219][t]->getval()), __fixed_sigmoid(_mem_logit[220][t]->getval()), __fixed_sigmoid(_mem_logit[221][t]->getval()), __fixed_sigmoid(_mem_logit[222][t]->getval()), __fixed_sigmoid(_mem_logit[223][t]->getval()), __fixed_sigmoid(_mem_logit[224][t]->getval()), __fixed_sigmoid(_mem_logit[225][t]->getval()), __fixed_sigmoid(_mem_logit[226][t]->getval()), __fixed_sigmoid(_mem_logit[227][t]->getval()), __fixed_sigmoid(_mem_logit[228][t]->getval()), __fixed_sigmoid(_mem_logit[229][t]->getval()), __fixed_sigmoid(_mem_logit[230][t]->getval()), __fixed_sigmoid(_mem_logit[231][t]->getval()), __fixed_sigmoid(_mem_logit[232][t]->getval()), __fixed_sigmoid(_mem_logit[233][t]->getval()), __fixed_sigmoid(_mem_logit[234][t]->getval()), __fixed_sigmoid(_mem_logit[235][t]->getval()), __fixed_sigmoid(_mem_logit[236][t]->getval()), __fixed_sigmoid(_mem_logit[237][t]->getval()), __fixed_sigmoid(_mem_logit[238][t]->getval()), __fixed_sigmoid(_mem_logit[239][t]->getval()), __fixed_sigmoid(_mem_logit[240][t]->getval()), __fixed_sigmoid(_mem_logit[241][t]->getval()), __fixed_sigmoid(_mem_logit[242][t]->getval()), __fixed_sigmoid(_mem_logit[243][t]->getval()), __fixed_sigmoid(_mem_logit[244][t]->getval()), __fixed_sigmoid(_mem_logit[245][t]->getval()), __fixed_sigmoid(_mem_logit[246][t]->getval()), __fixed_sigmoid(_mem_logit[247][t]->getval()), __fixed_sigmoid(_mem_logit[248][t]->getval()), __fixed_sigmoid(_mem_logit[249][t]->getval()), __fixed_sigmoid(_mem_logit[250][t]->getval()), __fixed_sigmoid(_mem_logit[251][t]->getval()), __fixed_sigmoid(_mem_logit[252][t]->getval()), __fixed_sigmoid(_mem_logit[253][t]->getval()), __fixed_sigmoid(_mem_logit[254][t]->getval()), __fixed_sigmoid(_mem_logit[255][t]->getval()), __fixed_sigmoid(_mem_logit[256][t]->getval()), __fixed_sigmoid(_mem_logit[257][t]->getval()), __fixed_sigmoid(_mem_logit[258][t]->getval()), __fixed_sigmoid(_mem_logit[259][t]->getval()), __fixed_sigmoid(_mem_logit[260][t]->getval()), __fixed_sigmoid(_mem_logit[261][t]->getval()), __fixed_sigmoid(_mem_logit[262][t]->getval()), __fixed_sigmoid(_mem_logit[263][t]->getval()), __fixed_sigmoid(_mem_logit[264][t]->getval()), __fixed_sigmoid(_mem_logit[265][t]->getval()), __fixed_sigmoid(_mem_logit[266][t]->getval()), __fixed_sigmoid(_mem_logit[267][t]->getval()), __fixed_sigmoid(_mem_logit[268][t]->getval()), __fixed_sigmoid(_mem_logit[269][t]->getval()), __fixed_sigmoid(_mem_logit[270][t]->getval()), __fixed_sigmoid(_mem_logit[271][t]->getval()), __fixed_sigmoid(_mem_logit[272][t]->getval()), __fixed_sigmoid(_mem_logit[273][t]->getval()), __fixed_sigmoid(_mem_logit[274][t]->getval()), __fixed_sigmoid(_mem_logit[275][t]->getval()), __fixed_sigmoid(_mem_logit[276][t]->getval())}))/__fixed_region_pop[r],0.00500000),Gaussian28870544.gen());
}
void _Var_region_rate::sample_cache()
{
  cache_val=(Gaussian28870544.init(dot(__fixed_county_map.row(r),vstack({__fixed_sigmoid(_mem_logit[0][t]->getcache()), __fixed_sigmoid(_mem_logit[1][t]->getcache()), __fixed_sigmoid(_mem_logit[2][t]->getcache()), __fixed_sigmoid(_mem_logit[3][t]->getcache()), __fixed_sigmoid(_mem_logit[4][t]->getcache()), __fixed_sigmoid(_mem_logit[5][t]->getcache()), __fixed_sigmoid(_mem_logit[6][t]->getcache()), __fixed_sigmoid(_mem_logit[7][t]->getcache()), __fixed_sigmoid(_mem_logit[8][t]->getcache()), __fixed_sigmoid(_mem_logit[9][t]->getcache()), __fixed_sigmoid(_mem_logit[10][t]->getcache()), __fixed_sigmoid(_mem_logit[11][t]->getcache()), __fixed_sigmoid(_mem_logit[12][t]->getcache()), __fixed_sigmoid(_mem_logit[13][t]->getcache()), __fixed_sigmoid(_mem_logit[14][t]->getcache()), __fixed_sigmoid(_mem_logit[15][t]->getcache()), __fixed_sigmoid(_mem_logit[16][t]->getcache()), __fixed_sigmoid(_mem_logit[17][t]->getcache()), __fixed_sigmoid(_mem_logit[18][t]->getcache()), __fixed_sigmoid(_mem_logit[19][t]->getcache()), __fixed_sigmoid(_mem_logit[20][t]->getcache()), __fixed_sigmoid(_mem_logit[21][t]->getcache()), __fixed_sigmoid(_mem_logit[22][t]->getcache()), __fixed_sigmoid(_mem_logit[23][t]->getcache()), __fixed_sigmoid(_mem_logit[24][t]->getcache()), __fixed_sigmoid(_mem_logit[25][t]->getcache()), __fixed_sigmoid(_mem_logit[26][t]->getcache()), __fixed_sigmoid(_mem_logit[27][t]->getcache()), __fixed_sigmoid(_mem_logit[28][t]->getcache()), __fixed_sigmoid(_mem_logit[29][t]->getcache()), __fixed_sigmoid(_mem_logit[30][t]->getcache()), __fixed_sigmoid(_mem_logit[31][t]->getcache()), __fixed_sigmoid(_mem_logit[32][t]->getcache()), __fixed_sigmoid(_mem_logit[33][t]->getcache()), __fixed_sigmoid(_mem_logit[34][t]->getcache()), __fixed_sigmoid(_mem_logit[35][t]->getcache()), __fixed_sigmoid(_mem_logit[36][t]->getcache()), __fixed_sigmoid(_mem_logit[37][t]->getcache()), __fixed_sigmoid(_mem_logit[38][t]->getcache()), __fixed_sigmoid(_mem_logit[39][t]->getcache()), __fixed_sigmoid(_mem_logit[40][t]->getcache()), __fixed_sigmoid(_mem_logit[41][t]->getcache()), __fixed_sigmoid(_mem_logit[42][t]->getcache()), __fixed_sigmoid(_mem_logit[43][t]->getcache()), __fixed_sigmoid(_mem_logit[44][t]->getcache()), __fixed_sigmoid(_mem_logit[45][t]->getcache()), __fixed_sigmoid(_mem_logit[46][t]->getcache()), __fixed_sigmoid(_mem_logit[47][t]->getcache()), __fixed_sigmoid(_mem_logit[48][t]->getcache()), __fixed_sigmoid(_mem_logit[49][t]->getcache()), __fixed_sigmoid(_mem_logit[50][t]->getcache()), __fixed_sigmoid(_mem_logit[51][t]->getcache()), __fixed_sigmoid(_mem_logit[52][t]->getcache()), __fixed_sigmoid(_mem_logit[53][t]->getcache()), __fixed_sigmoid(_mem_logit[54][t]->getcache()), __fixed_sigmoid(_mem_logit[55][t]->getcache()), __fixed_sigmoid(_mem_logit[56][t]->getcache()), __fixed_sigmoid(_mem_logit[57][t]->getcache()), __fixed_sigmoid(_mem_logit[58][t]->getcache()), __fixed_sigmoid(_mem_logit[59][t]->getcache()), __fixed_sigmoid(_mem_logit[60][t]->getcache()), __fixed_sigmoid(_mem_logit[61][t]->getcache()), __fixed_sigmoid(_mem_logit[62][t]->getcache()), __fixed_sigmoid(_mem_logit[63][t]->getcache()), __fixed_sigmoid(_mem_logit[64][t]->getcache()), __fixed_sigmoid(_mem_logit[65][t]->getcache()), __fixed_sigmoid(_mem_logit[66][t]->getcache()), __fixed_sigmoid(_mem_logit[67][t]->getcache()), __fixed_sigmoid(_mem_logit[68][t]->getcache()), __fixed_sigmoid(_mem_logit[69][t]->getcache()), __fixed_sigmoid(_mem_logit[70][t]->getcache()), __fixed_sigmoid(_mem_logit[71][t]->getcache()), __fixed_sigmoid(_mem_logit[72][t]->getcache()), __fixed_sigmoid(_mem_logit[73][t]->getcache()), __fixed_sigmoid(_mem_logit[74][t]->getcache()), __fixed_sigmoid(_mem_logit[75][t]->getcache()), __fixed_sigmoid(_mem_logit[76][t]->getcache()), __fixed_sigmoid(_mem_logit[77][t]->getcache()), __fixed_sigmoid(_mem_logit[78][t]->getcache()), __fixed_sigmoid(_mem_logit[79][t]->getcache()), __fixed_sigmoid(_mem_logit[80][t]->getcache()), __fixed_sigmoid(_mem_logit[81][t]->getcache()), __fixed_sigmoid(_mem_logit[82][t]->getcache()), __fixed_sigmoid(_mem_logit[83][t]->getcache()), __fixed_sigmoid(_mem_logit[84][t]->getcache()), __fixed_sigmoid(_mem_logit[85][t]->getcache()), __fixed_sigmoid(_mem_logit[86][t]->getcache()), __fixed_sigmoid(_mem_logit[87][t]->getcache()), __fixed_sigmoid(_mem_logit[88][t]->getcache()), __fixed_sigmoid(_mem_logit[89][t]->getcache()), __fixed_sigmoid(_mem_logit[90][t]->getcache()), __fixed_sigmoid(_mem_logit[91][t]->getcache()), __fixed_sigmoid(_mem_logit[92][t]->getcache()), __fixed_sigmoid(_mem_logit[93][t]->getcache()), __fixed_sigmoid(_mem_logit[94][t]->getcache()), __fixed_sigmoid(_mem_logit[95][t]->getcache()), __fixed_sigmoid(_mem_logit[96][t]->getcache()), __fixed_sigmoid(_mem_logit[97][t]->getcache()), __fixed_sigmoid(_mem_logit[98][t]->getcache()), __fixed_sigmoid(_mem_logit[99][t]->getcache()), __fixed_sigmoid(_mem_logit[100][t]->getcache()), __fixed_sigmoid(_mem_logit[101][t]->getcache()), __fixed_sigmoid(_mem_logit[102][t]->getcache()), __fixed_sigmoid(_mem_logit[103][t]->getcache()), __fixed_sigmoid(_mem_logit[104][t]->getcache()), __fixed_sigmoid(_mem_logit[105][t]->getcache()), __fixed_sigmoid(_mem_logit[106][t]->getcache()), __fixed_sigmoid(_mem_logit[107][t]->getcache()), __fixed_sigmoid(_mem_logit[108][t]->getcache()), __fixed_sigmoid(_mem_logit[109][t]->getcache()), __fixed_sigmoid(_mem_logit[110][t]->getcache()), __fixed_sigmoid(_mem_logit[111][t]->getcache()), __fixed_sigmoid(_mem_logit[112][t]->getcache()), __fixed_sigmoid(_mem_logit[113][t]->getcache()), __fixed_sigmoid(_mem_logit[114][t]->getcache()), __fixed_sigmoid(_mem_logit[115][t]->getcache()), __fixed_sigmoid(_mem_logit[116][t]->getcache()), __fixed_sigmoid(_mem_logit[117][t]->getcache()), __fixed_sigmoid(_mem_logit[118][t]->getcache()), __fixed_sigmoid(_mem_logit[119][t]->getcache()), __fixed_sigmoid(_mem_logit[120][t]->getcache()), __fixed_sigmoid(_mem_logit[121][t]->getcache()), __fixed_sigmoid(_mem_logit[122][t]->getcache()), __fixed_sigmoid(_mem_logit[123][t]->getcache()), __fixed_sigmoid(_mem_logit[124][t]->getcache()), __fixed_sigmoid(_mem_logit[125][t]->getcache()), __fixed_sigmoid(_mem_logit[126][t]->getcache()), __fixed_sigmoid(_mem_logit[127][t]->getcache()), __fixed_sigmoid(_mem_logit[128][t]->getcache()), __fixed_sigmoid(_mem_logit[129][t]->getcache()), __fixed_sigmoid(_mem_logit[130][t]->getcache()), __fixed_sigmoid(_mem_logit[131][t]->getcache()), __fixed_sigmoid(_mem_logit[132][t]->getcache()), __fixed_sigmoid(_mem_logit[133][t]->getcache()), __fixed_sigmoid(_mem_logit[134][t]->getcache()), __fixed_sigmoid(_mem_logit[135][t]->getcache()), __fixed_sigmoid(_mem_logit[136][t]->getcache()), __fixed_sigmoid(_mem_logit[137][t]->getcache()), __fixed_sigmoid(_mem_logit[138][t]->getcache()), __fixed_sigmoid(_mem_logit[139][t]->getcache()), __fixed_sigmoid(_mem_logit[140][t]->getcache()), __fixed_sigmoid(_mem_logit[141][t]->getcache()), __fixed_sigmoid(_mem_logit[142][t]->getcache()), __fixed_sigmoid(_mem_logit[143][t]->getcache()), __fixed_sigmoid(_mem_logit[144][t]->getcache()), __fixed_sigmoid(_mem_logit[145][t]->getcache()), __fixed_sigmoid(_mem_logit[146][t]->getcache()), __fixed_sigmoid(_mem_logit[147][t]->getcache()), __fixed_sigmoid(_mem_logit[148][t]->getcache()), __fixed_sigmoid(_mem_logit[149][t]->getcache()), __fixed_sigmoid(_mem_logit[150][t]->getcache()), __fixed_sigmoid(_mem_logit[151][t]->getcache()), __fixed_sigmoid(_mem_logit[152][t]->getcache()), __fixed_sigmoid(_mem_logit[153][t]->getcache()), __fixed_sigmoid(_mem_logit[154][t]->getcache()), __fixed_sigmoid(_mem_logit[155][t]->getcache()), __fixed_sigmoid(_mem_logit[156][t]->getcache()), __fixed_sigmoid(_mem_logit[157][t]->getcache()), __fixed_sigmoid(_mem_logit[158][t]->getcache()), __fixed_sigmoid(_mem_logit[159][t]->getcache()), __fixed_sigmoid(_mem_logit[160][t]->getcache()), __fixed_sigmoid(_mem_logit[161][t]->getcache()), __fixed_sigmoid(_mem_logit[162][t]->getcache()), __fixed_sigmoid(_mem_logit[163][t]->getcache()), __fixed_sigmoid(_mem_logit[164][t]->getcache()), __fixed_sigmoid(_mem_logit[165][t]->getcache()), __fixed_sigmoid(_mem_logit[166][t]->getcache()), __fixed_sigmoid(_mem_logit[167][t]->getcache()), __fixed_sigmoid(_mem_logit[168][t]->getcache()), __fixed_sigmoid(_mem_logit[169][t]->getcache()), __fixed_sigmoid(_mem_logit[170][t]->getcache()), __fixed_sigmoid(_mem_logit[171][t]->getcache()), __fixed_sigmoid(_mem_logit[172][t]->getcache()), __fixed_sigmoid(_mem_logit[173][t]->getcache()), __fixed_sigmoid(_mem_logit[174][t]->getcache()), __fixed_sigmoid(_mem_logit[175][t]->getcache()), __fixed_sigmoid(_mem_logit[176][t]->getcache()), __fixed_sigmoid(_mem_logit[177][t]->getcache()), __fixed_sigmoid(_mem_logit[178][t]->getcache()), __fixed_sigmoid(_mem_logit[179][t]->getcache()), __fixed_sigmoid(_mem_logit[180][t]->getcache()), __fixed_sigmoid(_mem_logit[181][t]->getcache()), __fixed_sigmoid(_mem_logit[182][t]->getcache()), __fixed_sigmoid(_mem_logit[183][t]->getcache()), __fixed_sigmoid(_mem_logit[184][t]->getcache()), __fixed_sigmoid(_mem_logit[185][t]->getcache()), __fixed_sigmoid(_mem_logit[186][t]->getcache()), __fixed_sigmoid(_mem_logit[187][t]->getcache()), __fixed_sigmoid(_mem_logit[188][t]->getcache()), __fixed_sigmoid(_mem_logit[189][t]->getcache()), __fixed_sigmoid(_mem_logit[190][t]->getcache()), __fixed_sigmoid(_mem_logit[191][t]->getcache()), __fixed_sigmoid(_mem_logit[192][t]->getcache()), __fixed_sigmoid(_mem_logit[193][t]->getcache()), __fixed_sigmoid(_mem_logit[194][t]->getcache()), __fixed_sigmoid(_mem_logit[195][t]->getcache()), __fixed_sigmoid(_mem_logit[196][t]->getcache()), __fixed_sigmoid(_mem_logit[197][t]->getcache()), __fixed_sigmoid(_mem_logit[198][t]->getcache()), __fixed_sigmoid(_mem_logit[199][t]->getcache()), __fixed_sigmoid(_mem_logit[200][t]->getcache()), __fixed_sigmoid(_mem_logit[201][t]->getcache()), __fixed_sigmoid(_mem_logit[202][t]->getcache()), __fixed_sigmoid(_mem_logit[203][t]->getcache()), __fixed_sigmoid(_mem_logit[204][t]->getcache()), __fixed_sigmoid(_mem_logit[205][t]->getcache()), __fixed_sigmoid(_mem_logit[206][t]->getcache()), __fixed_sigmoid(_mem_logit[207][t]->getcache()), __fixed_sigmoid(_mem_logit[208][t]->getcache()), __fixed_sigmoid(_mem_logit[209][t]->getcache()), __fixed_sigmoid(_mem_logit[210][t]->getcache()), __fixed_sigmoid(_mem_logit[211][t]->getcache()), __fixed_sigmoid(_mem_logit[212][t]->getcache()), __fixed_sigmoid(_mem_logit[213][t]->getcache()), __fixed_sigmoid(_mem_logit[214][t]->getcache()), __fixed_sigmoid(_mem_logit[215][t]->getcache()), __fixed_sigmoid(_mem_logit[216][t]->getcache()), __fixed_sigmoid(_mem_logit[217][t]->getcache()), __fixed_sigmoid(_mem_logit[218][t]->getcache()), __fixed_sigmoid(_mem_logit[219][t]->getcache()), __fixed_sigmoid(_mem_logit[220][t]->getcache()), __fixed_sigmoid(_mem_logit[221][t]->getcache()), __fixed_sigmoid(_mem_logit[222][t]->getcache()), __fixed_sigmoid(_mem_logit[223][t]->getcache()), __fixed_sigmoid(_mem_logit[224][t]->getcache()), __fixed_sigmoid(_mem_logit[225][t]->getcache()), __fixed_sigmoid(_mem_logit[226][t]->getcache()), __fixed_sigmoid(_mem_logit[227][t]->getcache()), __fixed_sigmoid(_mem_logit[228][t]->getcache()), __fixed_sigmoid(_mem_logit[229][t]->getcache()), __fixed_sigmoid(_mem_logit[230][t]->getcache()), __fixed_sigmoid(_mem_logit[231][t]->getcache()), __fixed_sigmoid(_mem_logit[232][t]->getcache()), __fixed_sigmoid(_mem_logit[233][t]->getcache()), __fixed_sigmoid(_mem_logit[234][t]->getcache()), __fixed_sigmoid(_mem_logit[235][t]->getcache()), __fixed_sigmoid(_mem_logit[236][t]->getcache()), __fixed_sigmoid(_mem_logit[237][t]->getcache()), __fixed_sigmoid(_mem_logit[238][t]->getcache()), __fixed_sigmoid(_mem_logit[239][t]->getcache()), __fixed_sigmoid(_mem_logit[240][t]->getcache()), __fixed_sigmoid(_mem_logit[241][t]->getcache()), __fixed_sigmoid(_mem_logit[242][t]->getcache()), __fixed_sigmoid(_mem_logit[243][t]->getcache()), __fixed_sigmoid(_mem_logit[244][t]->getcache()), __fixed_sigmoid(_mem_logit[245][t]->getcache()), __fixed_sigmoid(_mem_logit[246][t]->getcache()), __fixed_sigmoid(_mem_logit[247][t]->getcache()), __fixed_sigmoid(_mem_logit[248][t]->getcache()), __fixed_sigmoid(_mem_logit[249][t]->getcache()), __fixed_sigmoid(_mem_logit[250][t]->getcache()), __fixed_sigmoid(_mem_logit[251][t]->getcache()), __fixed_sigmoid(_mem_logit[252][t]->getcache()), __fixed_sigmoid(_mem_logit[253][t]->getcache()), __fixed_sigmoid(_mem_logit[254][t]->getcache()), __fixed_sigmoid(_mem_logit[255][t]->getcache()), __fixed_sigmoid(_mem_logit[256][t]->getcache()), __fixed_sigmoid(_mem_logit[257][t]->getcache()), __fixed_sigmoid(_mem_logit[258][t]->getcache()), __fixed_sigmoid(_mem_logit[259][t]->getcache()), __fixed_sigmoid(_mem_logit[260][t]->getcache()), __fixed_sigmoid(_mem_logit[261][t]->getcache()), __fixed_sigmoid(_mem_logit[262][t]->getcache()), __fixed_sigmoid(_mem_logit[263][t]->getcache()), __fixed_sigmoid(_mem_logit[264][t]->getcache()), __fixed_sigmoid(_mem_logit[265][t]->getcache()), __fixed_sigmoid(_mem_logit[266][t]->getcache()), __fixed_sigmoid(_mem_logit[267][t]->getcache()), __fixed_sigmoid(_mem_logit[268][t]->getcache()), __fixed_sigmoid(_mem_logit[269][t]->getcache()), __fixed_sigmoid(_mem_logit[270][t]->getcache()), __fixed_sigmoid(_mem_logit[271][t]->getcache()), __fixed_sigmoid(_mem_logit[272][t]->getcache()), __fixed_sigmoid(_mem_logit[273][t]->getcache()), __fixed_sigmoid(_mem_logit[274][t]->getcache()), __fixed_sigmoid(_mem_logit[275][t]->getcache()), __fixed_sigmoid(_mem_logit[276][t]->getcache())}))/__fixed_region_pop[r],0.00500000),Gaussian28870544.gen());
}
void _Var_region_rate::active_edge()
{
  _mem_logit[0][t]->add_contig(this);
  _mem_logit[100][t]->add_contig(this);
  _mem_logit[101][t]->add_contig(this);
  _mem_logit[102][t]->add_contig(this);
  _mem_logit[103][t]->add_contig(this);
  _mem_logit[104][t]->add_contig(this);
  _mem_logit[105][t]->add_contig(this);
  _mem_logit[106][t]->add_contig(this);
  _mem_logit[107][t]->add_contig(this);
  _mem_logit[108][t]->add_contig(this);
  _mem_logit[109][t]->add_contig(this);
  _mem_logit[10][t]->add_contig(this);
  _mem_logit[110][t]->add_contig(this);
  _mem_logit[111][t]->add_contig(this);
  _mem_logit[112][t]->add_contig(this);
  _mem_logit[113][t]->add_contig(this);
  _mem_logit[114][t]->add_contig(this);
  _mem_logit[115][t]->add_contig(this);
  _mem_logit[116][t]->add_contig(this);
  _mem_logit[117][t]->add_contig(this);
  _mem_logit[118][t]->add_contig(this);
  _mem_logit[119][t]->add_contig(this);
  _mem_logit[11][t]->add_contig(this);
  _mem_logit[120][t]->add_contig(this);
  _mem_logit[121][t]->add_contig(this);
  _mem_logit[122][t]->add_contig(this);
  _mem_logit[123][t]->add_contig(this);
  _mem_logit[124][t]->add_contig(this);
  _mem_logit[125][t]->add_contig(this);
  _mem_logit[126][t]->add_contig(this);
  _mem_logit[127][t]->add_contig(this);
  _mem_logit[128][t]->add_contig(this);
  _mem_logit[129][t]->add_contig(this);
  _mem_logit[12][t]->add_contig(this);
  _mem_logit[130][t]->add_contig(this);
  _mem_logit[131][t]->add_contig(this);
  _mem_logit[132][t]->add_contig(this);
  _mem_logit[133][t]->add_contig(this);
  _mem_logit[134][t]->add_contig(this);
  _mem_logit[135][t]->add_contig(this);
  _mem_logit[136][t]->add_contig(this);
  _mem_logit[137][t]->add_contig(this);
  _mem_logit[138][t]->add_contig(this);
  _mem_logit[139][t]->add_contig(this);
  _mem_logit[13][t]->add_contig(this);
  _mem_logit[140][t]->add_contig(this);
  _mem_logit[141][t]->add_contig(this);
  _mem_logit[142][t]->add_contig(this);
  _mem_logit[143][t]->add_contig(this);
  _mem_logit[144][t]->add_contig(this);
  _mem_logit[145][t]->add_contig(this);
  _mem_logit[146][t]->add_contig(this);
  _mem_logit[147][t]->add_contig(this);
  _mem_logit[148][t]->add_contig(this);
  _mem_logit[149][t]->add_contig(this);
  _mem_logit[14][t]->add_contig(this);
  _mem_logit[150][t]->add_contig(this);
  _mem_logit[151][t]->add_contig(this);
  _mem_logit[152][t]->add_contig(this);
  _mem_logit[153][t]->add_contig(this);
  _mem_logit[154][t]->add_contig(this);
  _mem_logit[155][t]->add_contig(this);
  _mem_logit[156][t]->add_contig(this);
  _mem_logit[157][t]->add_contig(this);
  _mem_logit[158][t]->add_contig(this);
  _mem_logit[159][t]->add_contig(this);
  _mem_logit[15][t]->add_contig(this);
  _mem_logit[160][t]->add_contig(this);
  _mem_logit[161][t]->add_contig(this);
  _mem_logit[162][t]->add_contig(this);
  _mem_logit[163][t]->add_contig(this);
  _mem_logit[164][t]->add_contig(this);
  _mem_logit[165][t]->add_contig(this);
  _mem_logit[166][t]->add_contig(this);
  _mem_logit[167][t]->add_contig(this);
  _mem_logit[168][t]->add_contig(this);
  _mem_logit[169][t]->add_contig(this);
  _mem_logit[16][t]->add_contig(this);
  _mem_logit[170][t]->add_contig(this);
  _mem_logit[171][t]->add_contig(this);
  _mem_logit[172][t]->add_contig(this);
  _mem_logit[173][t]->add_contig(this);
  _mem_logit[174][t]->add_contig(this);
  _mem_logit[175][t]->add_contig(this);
  _mem_logit[176][t]->add_contig(this);
  _mem_logit[177][t]->add_contig(this);
  _mem_logit[178][t]->add_contig(this);
  _mem_logit[179][t]->add_contig(this);
  _mem_logit[17][t]->add_contig(this);
  _mem_logit[180][t]->add_contig(this);
  _mem_logit[181][t]->add_contig(this);
  _mem_logit[182][t]->add_contig(this);
  _mem_logit[183][t]->add_contig(this);
  _mem_logit[184][t]->add_contig(this);
  _mem_logit[185][t]->add_contig(this);
  _mem_logit[186][t]->add_contig(this);
  _mem_logit[187][t]->add_contig(this);
  _mem_logit[188][t]->add_contig(this);
  _mem_logit[189][t]->add_contig(this);
  _mem_logit[18][t]->add_contig(this);
  _mem_logit[190][t]->add_contig(this);
  _mem_logit[191][t]->add_contig(this);
  _mem_logit[192][t]->add_contig(this);
  _mem_logit[193][t]->add_contig(this);
  _mem_logit[194][t]->add_contig(this);
  _mem_logit[195][t]->add_contig(this);
  _mem_logit[196][t]->add_contig(this);
  _mem_logit[197][t]->add_contig(this);
  _mem_logit[198][t]->add_contig(this);
  _mem_logit[199][t]->add_contig(this);
  _mem_logit[19][t]->add_contig(this);
  _mem_logit[1][t]->add_contig(this);
  _mem_logit[200][t]->add_contig(this);
  _mem_logit[201][t]->add_contig(this);
  _mem_logit[202][t]->add_contig(this);
  _mem_logit[203][t]->add_contig(this);
  _mem_logit[204][t]->add_contig(this);
  _mem_logit[205][t]->add_contig(this);
  _mem_logit[206][t]->add_contig(this);
  _mem_logit[207][t]->add_contig(this);
  _mem_logit[208][t]->add_contig(this);
  _mem_logit[209][t]->add_contig(this);
  _mem_logit[20][t]->add_contig(this);
  _mem_logit[210][t]->add_contig(this);
  _mem_logit[211][t]->add_contig(this);
  _mem_logit[212][t]->add_contig(this);
  _mem_logit[213][t]->add_contig(this);
  _mem_logit[214][t]->add_contig(this);
  _mem_logit[215][t]->add_contig(this);
  _mem_logit[216][t]->add_contig(this);
  _mem_logit[217][t]->add_contig(this);
  _mem_logit[218][t]->add_contig(this);
  _mem_logit[219][t]->add_contig(this);
  _mem_logit[21][t]->add_contig(this);
  _mem_logit[220][t]->add_contig(this);
  _mem_logit[221][t]->add_contig(this);
  _mem_logit[222][t]->add_contig(this);
  _mem_logit[223][t]->add_contig(this);
  _mem_logit[224][t]->add_contig(this);
  _mem_logit[225][t]->add_contig(this);
  _mem_logit[226][t]->add_contig(this);
  _mem_logit[227][t]->add_contig(this);
  _mem_logit[228][t]->add_contig(this);
  _mem_logit[229][t]->add_contig(this);
  _mem_logit[22][t]->add_contig(this);
  _mem_logit[230][t]->add_contig(this);
  _mem_logit[231][t]->add_contig(this);
  _mem_logit[232][t]->add_contig(this);
  _mem_logit[233][t]->add_contig(this);
  _mem_logit[234][t]->add_contig(this);
  _mem_logit[235][t]->add_contig(this);
  _mem_logit[236][t]->add_contig(this);
  _mem_logit[237][t]->add_contig(this);
  _mem_logit[238][t]->add_contig(this);
  _mem_logit[239][t]->add_contig(this);
  _mem_logit[23][t]->add_contig(this);
  _mem_logit[240][t]->add_contig(this);
  _mem_logit[241][t]->add_contig(this);
  _mem_logit[242][t]->add_contig(this);
  _mem_logit[243][t]->add_contig(this);
  _mem_logit[244][t]->add_contig(this);
  _mem_logit[245][t]->add_contig(this);
  _mem_logit[246][t]->add_contig(this);
  _mem_logit[247][t]->add_contig(this);
  _mem_logit[248][t]->add_contig(this);
  _mem_logit[249][t]->add_contig(this);
  _mem_logit[24][t]->add_contig(this);
  _mem_logit[250][t]->add_contig(this);
  _mem_logit[251][t]->add_contig(this);
  _mem_logit[252][t]->add_contig(this);
  _mem_logit[253][t]->add_contig(this);
  _mem_logit[254][t]->add_contig(this);
  _mem_logit[255][t]->add_contig(this);
  _mem_logit[256][t]->add_contig(this);
  _mem_logit[257][t]->add_contig(this);
  _mem_logit[258][t]->add_contig(this);
  _mem_logit[259][t]->add_contig(this);
  _mem_logit[25][t]->add_contig(this);
  _mem_logit[260][t]->add_contig(this);
  _mem_logit[261][t]->add_contig(this);
  _mem_logit[262][t]->add_contig(this);
  _mem_logit[263][t]->add_contig(this);
  _mem_logit[264][t]->add_contig(this);
  _mem_logit[265][t]->add_contig(this);
  _mem_logit[266][t]->add_contig(this);
  _mem_logit[267][t]->add_contig(this);
  _mem_logit[268][t]->add_contig(this);
  _mem_logit[269][t]->add_contig(this);
  _mem_logit[26][t]->add_contig(this);
  _mem_logit[270][t]->add_contig(this);
  _mem_logit[271][t]->add_contig(this);
  _mem_logit[272][t]->add_contig(this);
  _mem_logit[273][t]->add_contig(this);
  _mem_logit[274][t]->add_contig(this);
  _mem_logit[275][t]->add_contig(this);
  _mem_logit[276][t]->add_contig(this);
  _mem_logit[27][t]->add_contig(this);
  _mem_logit[28][t]->add_contig(this);
  _mem_logit[29][t]->add_contig(this);
  _mem_logit[2][t]->add_contig(this);
  _mem_logit[30][t]->add_contig(this);
  _mem_logit[31][t]->add_contig(this);
  _mem_logit[32][t]->add_contig(this);
  _mem_logit[33][t]->add_contig(this);
  _mem_logit[34][t]->add_contig(this);
  _mem_logit[35][t]->add_contig(this);
  _mem_logit[36][t]->add_contig(this);
  _mem_logit[37][t]->add_contig(this);
  _mem_logit[38][t]->add_contig(this);
  _mem_logit[39][t]->add_contig(this);
  _mem_logit[3][t]->add_contig(this);
  _mem_logit[40][t]->add_contig(this);
  _mem_logit[41][t]->add_contig(this);
  _mem_logit[42][t]->add_contig(this);
  _mem_logit[43][t]->add_contig(this);
  _mem_logit[44][t]->add_contig(this);
  _mem_logit[45][t]->add_contig(this);
  _mem_logit[46][t]->add_contig(this);
  _mem_logit[47][t]->add_contig(this);
  _mem_logit[48][t]->add_contig(this);
  _mem_logit[49][t]->add_contig(this);
  _mem_logit[4][t]->add_contig(this);
  _mem_logit[50][t]->add_contig(this);
  _mem_logit[51][t]->add_contig(this);
  _mem_logit[52][t]->add_contig(this);
  _mem_logit[53][t]->add_contig(this);
  _mem_logit[54][t]->add_contig(this);
  _mem_logit[55][t]->add_contig(this);
  _mem_logit[56][t]->add_contig(this);
  _mem_logit[57][t]->add_contig(this);
  _mem_logit[58][t]->add_contig(this);
  _mem_logit[59][t]->add_contig(this);
  _mem_logit[5][t]->add_contig(this);
  _mem_logit[60][t]->add_contig(this);
  _mem_logit[61][t]->add_contig(this);
  _mem_logit[62][t]->add_contig(this);
  _mem_logit[63][t]->add_contig(this);
  _mem_logit[64][t]->add_contig(this);
  _mem_logit[65][t]->add_contig(this);
  _mem_logit[66][t]->add_contig(this);
  _mem_logit[67][t]->add_contig(this);
  _mem_logit[68][t]->add_contig(this);
  _mem_logit[69][t]->add_contig(this);
  _mem_logit[6][t]->add_contig(this);
  _mem_logit[70][t]->add_contig(this);
  _mem_logit[71][t]->add_contig(this);
  _mem_logit[72][t]->add_contig(this);
  _mem_logit[73][t]->add_contig(this);
  _mem_logit[74][t]->add_contig(this);
  _mem_logit[75][t]->add_contig(this);
  _mem_logit[76][t]->add_contig(this);
  _mem_logit[77][t]->add_contig(this);
  _mem_logit[78][t]->add_contig(this);
  _mem_logit[79][t]->add_contig(this);
  _mem_logit[7][t]->add_contig(this);
  _mem_logit[80][t]->add_contig(this);
  _mem_logit[81][t]->add_contig(this);
  _mem_logit[82][t]->add_contig(this);
  _mem_logit[83][t]->add_contig(this);
  _mem_logit[84][t]->add_contig(this);
  _mem_logit[85][t]->add_contig(this);
  _mem_logit[86][t]->add_contig(this);
  _mem_logit[87][t]->add_contig(this);
  _mem_logit[88][t]->add_contig(this);
  _mem_logit[89][t]->add_contig(this);
  _mem_logit[8][t]->add_contig(this);
  _mem_logit[90][t]->add_contig(this);
  _mem_logit[91][t]->add_contig(this);
  _mem_logit[92][t]->add_contig(this);
  _mem_logit[93][t]->add_contig(this);
  _mem_logit[94][t]->add_contig(this);
  _mem_logit[95][t]->add_contig(this);
  _mem_logit[96][t]->add_contig(this);
  _mem_logit[97][t]->add_contig(this);
  _mem_logit[98][t]->add_contig(this);
  _mem_logit[99][t]->add_contig(this);
  _mem_logit[9][t]->add_contig(this);
  _mem_logit[0][t]->add_child(this);
  _mem_logit[100][t]->add_child(this);
  _mem_logit[101][t]->add_child(this);
  _mem_logit[102][t]->add_child(this);
  _mem_logit[103][t]->add_child(this);
  _mem_logit[104][t]->add_child(this);
  _mem_logit[105][t]->add_child(this);
  _mem_logit[106][t]->add_child(this);
  _mem_logit[107][t]->add_child(this);
  _mem_logit[108][t]->add_child(this);
  _mem_logit[109][t]->add_child(this);
  _mem_logit[10][t]->add_child(this);
  _mem_logit[110][t]->add_child(this);
  _mem_logit[111][t]->add_child(this);
  _mem_logit[112][t]->add_child(this);
  _mem_logit[113][t]->add_child(this);
  _mem_logit[114][t]->add_child(this);
  _mem_logit[115][t]->add_child(this);
  _mem_logit[116][t]->add_child(this);
  _mem_logit[117][t]->add_child(this);
  _mem_logit[118][t]->add_child(this);
  _mem_logit[119][t]->add_child(this);
  _mem_logit[11][t]->add_child(this);
  _mem_logit[120][t]->add_child(this);
  _mem_logit[121][t]->add_child(this);
  _mem_logit[122][t]->add_child(this);
  _mem_logit[123][t]->add_child(this);
  _mem_logit[124][t]->add_child(this);
  _mem_logit[125][t]->add_child(this);
  _mem_logit[126][t]->add_child(this);
  _mem_logit[127][t]->add_child(this);
  _mem_logit[128][t]->add_child(this);
  _mem_logit[129][t]->add_child(this);
  _mem_logit[12][t]->add_child(this);
  _mem_logit[130][t]->add_child(this);
  _mem_logit[131][t]->add_child(this);
  _mem_logit[132][t]->add_child(this);
  _mem_logit[133][t]->add_child(this);
  _mem_logit[134][t]->add_child(this);
  _mem_logit[135][t]->add_child(this);
  _mem_logit[136][t]->add_child(this);
  _mem_logit[137][t]->add_child(this);
  _mem_logit[138][t]->add_child(this);
  _mem_logit[139][t]->add_child(this);
  _mem_logit[13][t]->add_child(this);
  _mem_logit[140][t]->add_child(this);
  _mem_logit[141][t]->add_child(this);
  _mem_logit[142][t]->add_child(this);
  _mem_logit[143][t]->add_child(this);
  _mem_logit[144][t]->add_child(this);
  _mem_logit[145][t]->add_child(this);
  _mem_logit[146][t]->add_child(this);
  _mem_logit[147][t]->add_child(this);
  _mem_logit[148][t]->add_child(this);
  _mem_logit[149][t]->add_child(this);
  _mem_logit[14][t]->add_child(this);
  _mem_logit[150][t]->add_child(this);
  _mem_logit[151][t]->add_child(this);
  _mem_logit[152][t]->add_child(this);
  _mem_logit[153][t]->add_child(this);
  _mem_logit[154][t]->add_child(this);
  _mem_logit[155][t]->add_child(this);
  _mem_logit[156][t]->add_child(this);
  _mem_logit[157][t]->add_child(this);
  _mem_logit[158][t]->add_child(this);
  _mem_logit[159][t]->add_child(this);
  _mem_logit[15][t]->add_child(this);
  _mem_logit[160][t]->add_child(this);
  _mem_logit[161][t]->add_child(this);
  _mem_logit[162][t]->add_child(this);
  _mem_logit[163][t]->add_child(this);
  _mem_logit[164][t]->add_child(this);
  _mem_logit[165][t]->add_child(this);
  _mem_logit[166][t]->add_child(this);
  _mem_logit[167][t]->add_child(this);
  _mem_logit[168][t]->add_child(this);
  _mem_logit[169][t]->add_child(this);
  _mem_logit[16][t]->add_child(this);
  _mem_logit[170][t]->add_child(this);
  _mem_logit[171][t]->add_child(this);
  _mem_logit[172][t]->add_child(this);
  _mem_logit[173][t]->add_child(this);
  _mem_logit[174][t]->add_child(this);
  _mem_logit[175][t]->add_child(this);
  _mem_logit[176][t]->add_child(this);
  _mem_logit[177][t]->add_child(this);
  _mem_logit[178][t]->add_child(this);
  _mem_logit[179][t]->add_child(this);
  _mem_logit[17][t]->add_child(this);
  _mem_logit[180][t]->add_child(this);
  _mem_logit[181][t]->add_child(this);
  _mem_logit[182][t]->add_child(this);
  _mem_logit[183][t]->add_child(this);
  _mem_logit[184][t]->add_child(this);
  _mem_logit[185][t]->add_child(this);
  _mem_logit[186][t]->add_child(this);
  _mem_logit[187][t]->add_child(this);
  _mem_logit[188][t]->add_child(this);
  _mem_logit[189][t]->add_child(this);
  _mem_logit[18][t]->add_child(this);
  _mem_logit[190][t]->add_child(this);
  _mem_logit[191][t]->add_child(this);
  _mem_logit[192][t]->add_child(this);
  _mem_logit[193][t]->add_child(this);
  _mem_logit[194][t]->add_child(this);
  _mem_logit[195][t]->add_child(this);
  _mem_logit[196][t]->add_child(this);
  _mem_logit[197][t]->add_child(this);
  _mem_logit[198][t]->add_child(this);
  _mem_logit[199][t]->add_child(this);
  _mem_logit[19][t]->add_child(this);
  _mem_logit[1][t]->add_child(this);
  _mem_logit[200][t]->add_child(this);
  _mem_logit[201][t]->add_child(this);
  _mem_logit[202][t]->add_child(this);
  _mem_logit[203][t]->add_child(this);
  _mem_logit[204][t]->add_child(this);
  _mem_logit[205][t]->add_child(this);
  _mem_logit[206][t]->add_child(this);
  _mem_logit[207][t]->add_child(this);
  _mem_logit[208][t]->add_child(this);
  _mem_logit[209][t]->add_child(this);
  _mem_logit[20][t]->add_child(this);
  _mem_logit[210][t]->add_child(this);
  _mem_logit[211][t]->add_child(this);
  _mem_logit[212][t]->add_child(this);
  _mem_logit[213][t]->add_child(this);
  _mem_logit[214][t]->add_child(this);
  _mem_logit[215][t]->add_child(this);
  _mem_logit[216][t]->add_child(this);
  _mem_logit[217][t]->add_child(this);
  _mem_logit[218][t]->add_child(this);
  _mem_logit[219][t]->add_child(this);
  _mem_logit[21][t]->add_child(this);
  _mem_logit[220][t]->add_child(this);
  _mem_logit[221][t]->add_child(this);
  _mem_logit[222][t]->add_child(this);
  _mem_logit[223][t]->add_child(this);
  _mem_logit[224][t]->add_child(this);
  _mem_logit[225][t]->add_child(this);
  _mem_logit[226][t]->add_child(this);
  _mem_logit[227][t]->add_child(this);
  _mem_logit[228][t]->add_child(this);
  _mem_logit[229][t]->add_child(this);
  _mem_logit[22][t]->add_child(this);
  _mem_logit[230][t]->add_child(this);
  _mem_logit[231][t]->add_child(this);
  _mem_logit[232][t]->add_child(this);
  _mem_logit[233][t]->add_child(this);
  _mem_logit[234][t]->add_child(this);
  _mem_logit[235][t]->add_child(this);
  _mem_logit[236][t]->add_child(this);
  _mem_logit[237][t]->add_child(this);
  _mem_logit[238][t]->add_child(this);
  _mem_logit[239][t]->add_child(this);
  _mem_logit[23][t]->add_child(this);
  _mem_logit[240][t]->add_child(this);
  _mem_logit[241][t]->add_child(this);
  _mem_logit[242][t]->add_child(this);
  _mem_logit[243][t]->add_child(this);
  _mem_logit[244][t]->add_child(this);
  _mem_logit[245][t]->add_child(this);
  _mem_logit[246][t]->add_child(this);
  _mem_logit[247][t]->add_child(this);
  _mem_logit[248][t]->add_child(this);
  _mem_logit[249][t]->add_child(this);
  _mem_logit[24][t]->add_child(this);
  _mem_logit[250][t]->add_child(this);
  _mem_logit[251][t]->add_child(this);
  _mem_logit[252][t]->add_child(this);
  _mem_logit[253][t]->add_child(this);
  _mem_logit[254][t]->add_child(this);
  _mem_logit[255][t]->add_child(this);
  _mem_logit[256][t]->add_child(this);
  _mem_logit[257][t]->add_child(this);
  _mem_logit[258][t]->add_child(this);
  _mem_logit[259][t]->add_child(this);
  _mem_logit[25][t]->add_child(this);
  _mem_logit[260][t]->add_child(this);
  _mem_logit[261][t]->add_child(this);
  _mem_logit[262][t]->add_child(this);
  _mem_logit[263][t]->add_child(this);
  _mem_logit[264][t]->add_child(this);
  _mem_logit[265][t]->add_child(this);
  _mem_logit[266][t]->add_child(this);
  _mem_logit[267][t]->add_child(this);
  _mem_logit[268][t]->add_child(this);
  _mem_logit[269][t]->add_child(this);
  _mem_logit[26][t]->add_child(this);
  _mem_logit[270][t]->add_child(this);
  _mem_logit[271][t]->add_child(this);
  _mem_logit[272][t]->add_child(this);
  _mem_logit[273][t]->add_child(this);
  _mem_logit[274][t]->add_child(this);
  _mem_logit[275][t]->add_child(this);
  _mem_logit[276][t]->add_child(this);
  _mem_logit[27][t]->add_child(this);
  _mem_logit[28][t]->add_child(this);
  _mem_logit[29][t]->add_child(this);
  _mem_logit[2][t]->add_child(this);
  _mem_logit[30][t]->add_child(this);
  _mem_logit[31][t]->add_child(this);
  _mem_logit[32][t]->add_child(this);
  _mem_logit[33][t]->add_child(this);
  _mem_logit[34][t]->add_child(this);
  _mem_logit[35][t]->add_child(this);
  _mem_logit[36][t]->add_child(this);
  _mem_logit[37][t]->add_child(this);
  _mem_logit[38][t]->add_child(this);
  _mem_logit[39][t]->add_child(this);
  _mem_logit[3][t]->add_child(this);
  _mem_logit[40][t]->add_child(this);
  _mem_logit[41][t]->add_child(this);
  _mem_logit[42][t]->add_child(this);
  _mem_logit[43][t]->add_child(this);
  _mem_logit[44][t]->add_child(this);
  _mem_logit[45][t]->add_child(this);
  _mem_logit[46][t]->add_child(this);
  _mem_logit[47][t]->add_child(this);
  _mem_logit[48][t]->add_child(this);
  _mem_logit[49][t]->add_child(this);
  _mem_logit[4][t]->add_child(this);
  _mem_logit[50][t]->add_child(this);
  _mem_logit[51][t]->add_child(this);
  _mem_logit[52][t]->add_child(this);
  _mem_logit[53][t]->add_child(this);
  _mem_logit[54][t]->add_child(this);
  _mem_logit[55][t]->add_child(this);
  _mem_logit[56][t]->add_child(this);
  _mem_logit[57][t]->add_child(this);
  _mem_logit[58][t]->add_child(this);
  _mem_logit[59][t]->add_child(this);
  _mem_logit[5][t]->add_child(this);
  _mem_logit[60][t]->add_child(this);
  _mem_logit[61][t]->add_child(this);
  _mem_logit[62][t]->add_child(this);
  _mem_logit[63][t]->add_child(this);
  _mem_logit[64][t]->add_child(this);
  _mem_logit[65][t]->add_child(this);
  _mem_logit[66][t]->add_child(this);
  _mem_logit[67][t]->add_child(this);
  _mem_logit[68][t]->add_child(this);
  _mem_logit[69][t]->add_child(this);
  _mem_logit[6][t]->add_child(this);
  _mem_logit[70][t]->add_child(this);
  _mem_logit[71][t]->add_child(this);
  _mem_logit[72][t]->add_child(this);
  _mem_logit[73][t]->add_child(this);
  _mem_logit[74][t]->add_child(this);
  _mem_logit[75][t]->add_child(this);
  _mem_logit[76][t]->add_child(this);
  _mem_logit[77][t]->add_child(this);
  _mem_logit[78][t]->add_child(this);
  _mem_logit[79][t]->add_child(this);
  _mem_logit[7][t]->add_child(this);
  _mem_logit[80][t]->add_child(this);
  _mem_logit[81][t]->add_child(this);
  _mem_logit[82][t]->add_child(this);
  _mem_logit[83][t]->add_child(this);
  _mem_logit[84][t]->add_child(this);
  _mem_logit[85][t]->add_child(this);
  _mem_logit[86][t]->add_child(this);
  _mem_logit[87][t]->add_child(this);
  _mem_logit[88][t]->add_child(this);
  _mem_logit[89][t]->add_child(this);
  _mem_logit[8][t]->add_child(this);
  _mem_logit[90][t]->add_child(this);
  _mem_logit[91][t]->add_child(this);
  _mem_logit[92][t]->add_child(this);
  _mem_logit[93][t]->add_child(this);
  _mem_logit[94][t]->add_child(this);
  _mem_logit[95][t]->add_child(this);
  _mem_logit[96][t]->add_child(this);
  _mem_logit[97][t]->add_child(this);
  _mem_logit[98][t]->add_child(this);
  _mem_logit[99][t]->add_child(this);
  _mem_logit[9][t]->add_child(this);
}
void _Var_region_rate::remove_edge()
{
  _mem_logit[0][t]->erase_contig(this);
  _mem_logit[100][t]->erase_contig(this);
  _mem_logit[101][t]->erase_contig(this);
  _mem_logit[102][t]->erase_contig(this);
  _mem_logit[103][t]->erase_contig(this);
  _mem_logit[104][t]->erase_contig(this);
  _mem_logit[105][t]->erase_contig(this);
  _mem_logit[106][t]->erase_contig(this);
  _mem_logit[107][t]->erase_contig(this);
  _mem_logit[108][t]->erase_contig(this);
  _mem_logit[109][t]->erase_contig(this);
  _mem_logit[10][t]->erase_contig(this);
  _mem_logit[110][t]->erase_contig(this);
  _mem_logit[111][t]->erase_contig(this);
  _mem_logit[112][t]->erase_contig(this);
  _mem_logit[113][t]->erase_contig(this);
  _mem_logit[114][t]->erase_contig(this);
  _mem_logit[115][t]->erase_contig(this);
  _mem_logit[116][t]->erase_contig(this);
  _mem_logit[117][t]->erase_contig(this);
  _mem_logit[118][t]->erase_contig(this);
  _mem_logit[119][t]->erase_contig(this);
  _mem_logit[11][t]->erase_contig(this);
  _mem_logit[120][t]->erase_contig(this);
  _mem_logit[121][t]->erase_contig(this);
  _mem_logit[122][t]->erase_contig(this);
  _mem_logit[123][t]->erase_contig(this);
  _mem_logit[124][t]->erase_contig(this);
  _mem_logit[125][t]->erase_contig(this);
  _mem_logit[126][t]->erase_contig(this);
  _mem_logit[127][t]->erase_contig(this);
  _mem_logit[128][t]->erase_contig(this);
  _mem_logit[129][t]->erase_contig(this);
  _mem_logit[12][t]->erase_contig(this);
  _mem_logit[130][t]->erase_contig(this);
  _mem_logit[131][t]->erase_contig(this);
  _mem_logit[132][t]->erase_contig(this);
  _mem_logit[133][t]->erase_contig(this);
  _mem_logit[134][t]->erase_contig(this);
  _mem_logit[135][t]->erase_contig(this);
  _mem_logit[136][t]->erase_contig(this);
  _mem_logit[137][t]->erase_contig(this);
  _mem_logit[138][t]->erase_contig(this);
  _mem_logit[139][t]->erase_contig(this);
  _mem_logit[13][t]->erase_contig(this);
  _mem_logit[140][t]->erase_contig(this);
  _mem_logit[141][t]->erase_contig(this);
  _mem_logit[142][t]->erase_contig(this);
  _mem_logit[143][t]->erase_contig(this);
  _mem_logit[144][t]->erase_contig(this);
  _mem_logit[145][t]->erase_contig(this);
  _mem_logit[146][t]->erase_contig(this);
  _mem_logit[147][t]->erase_contig(this);
  _mem_logit[148][t]->erase_contig(this);
  _mem_logit[149][t]->erase_contig(this);
  _mem_logit[14][t]->erase_contig(this);
  _mem_logit[150][t]->erase_contig(this);
  _mem_logit[151][t]->erase_contig(this);
  _mem_logit[152][t]->erase_contig(this);
  _mem_logit[153][t]->erase_contig(this);
  _mem_logit[154][t]->erase_contig(this);
  _mem_logit[155][t]->erase_contig(this);
  _mem_logit[156][t]->erase_contig(this);
  _mem_logit[157][t]->erase_contig(this);
  _mem_logit[158][t]->erase_contig(this);
  _mem_logit[159][t]->erase_contig(this);
  _mem_logit[15][t]->erase_contig(this);
  _mem_logit[160][t]->erase_contig(this);
  _mem_logit[161][t]->erase_contig(this);
  _mem_logit[162][t]->erase_contig(this);
  _mem_logit[163][t]->erase_contig(this);
  _mem_logit[164][t]->erase_contig(this);
  _mem_logit[165][t]->erase_contig(this);
  _mem_logit[166][t]->erase_contig(this);
  _mem_logit[167][t]->erase_contig(this);
  _mem_logit[168][t]->erase_contig(this);
  _mem_logit[169][t]->erase_contig(this);
  _mem_logit[16][t]->erase_contig(this);
  _mem_logit[170][t]->erase_contig(this);
  _mem_logit[171][t]->erase_contig(this);
  _mem_logit[172][t]->erase_contig(this);
  _mem_logit[173][t]->erase_contig(this);
  _mem_logit[174][t]->erase_contig(this);
  _mem_logit[175][t]->erase_contig(this);
  _mem_logit[176][t]->erase_contig(this);
  _mem_logit[177][t]->erase_contig(this);
  _mem_logit[178][t]->erase_contig(this);
  _mem_logit[179][t]->erase_contig(this);
  _mem_logit[17][t]->erase_contig(this);
  _mem_logit[180][t]->erase_contig(this);
  _mem_logit[181][t]->erase_contig(this);
  _mem_logit[182][t]->erase_contig(this);
  _mem_logit[183][t]->erase_contig(this);
  _mem_logit[184][t]->erase_contig(this);
  _mem_logit[185][t]->erase_contig(this);
  _mem_logit[186][t]->erase_contig(this);
  _mem_logit[187][t]->erase_contig(this);
  _mem_logit[188][t]->erase_contig(this);
  _mem_logit[189][t]->erase_contig(this);
  _mem_logit[18][t]->erase_contig(this);
  _mem_logit[190][t]->erase_contig(this);
  _mem_logit[191][t]->erase_contig(this);
  _mem_logit[192][t]->erase_contig(this);
  _mem_logit[193][t]->erase_contig(this);
  _mem_logit[194][t]->erase_contig(this);
  _mem_logit[195][t]->erase_contig(this);
  _mem_logit[196][t]->erase_contig(this);
  _mem_logit[197][t]->erase_contig(this);
  _mem_logit[198][t]->erase_contig(this);
  _mem_logit[199][t]->erase_contig(this);
  _mem_logit[19][t]->erase_contig(this);
  _mem_logit[1][t]->erase_contig(this);
  _mem_logit[200][t]->erase_contig(this);
  _mem_logit[201][t]->erase_contig(this);
  _mem_logit[202][t]->erase_contig(this);
  _mem_logit[203][t]->erase_contig(this);
  _mem_logit[204][t]->erase_contig(this);
  _mem_logit[205][t]->erase_contig(this);
  _mem_logit[206][t]->erase_contig(this);
  _mem_logit[207][t]->erase_contig(this);
  _mem_logit[208][t]->erase_contig(this);
  _mem_logit[209][t]->erase_contig(this);
  _mem_logit[20][t]->erase_contig(this);
  _mem_logit[210][t]->erase_contig(this);
  _mem_logit[211][t]->erase_contig(this);
  _mem_logit[212][t]->erase_contig(this);
  _mem_logit[213][t]->erase_contig(this);
  _mem_logit[214][t]->erase_contig(this);
  _mem_logit[215][t]->erase_contig(this);
  _mem_logit[216][t]->erase_contig(this);
  _mem_logit[217][t]->erase_contig(this);
  _mem_logit[218][t]->erase_contig(this);
  _mem_logit[219][t]->erase_contig(this);
  _mem_logit[21][t]->erase_contig(this);
  _mem_logit[220][t]->erase_contig(this);
  _mem_logit[221][t]->erase_contig(this);
  _mem_logit[222][t]->erase_contig(this);
  _mem_logit[223][t]->erase_contig(this);
  _mem_logit[224][t]->erase_contig(this);
  _mem_logit[225][t]->erase_contig(this);
  _mem_logit[226][t]->erase_contig(this);
  _mem_logit[227][t]->erase_contig(this);
  _mem_logit[228][t]->erase_contig(this);
  _mem_logit[229][t]->erase_contig(this);
  _mem_logit[22][t]->erase_contig(this);
  _mem_logit[230][t]->erase_contig(this);
  _mem_logit[231][t]->erase_contig(this);
  _mem_logit[232][t]->erase_contig(this);
  _mem_logit[233][t]->erase_contig(this);
  _mem_logit[234][t]->erase_contig(this);
  _mem_logit[235][t]->erase_contig(this);
  _mem_logit[236][t]->erase_contig(this);
  _mem_logit[237][t]->erase_contig(this);
  _mem_logit[238][t]->erase_contig(this);
  _mem_logit[239][t]->erase_contig(this);
  _mem_logit[23][t]->erase_contig(this);
  _mem_logit[240][t]->erase_contig(this);
  _mem_logit[241][t]->erase_contig(this);
  _mem_logit[242][t]->erase_contig(this);
  _mem_logit[243][t]->erase_contig(this);
  _mem_logit[244][t]->erase_contig(this);
  _mem_logit[245][t]->erase_contig(this);
  _mem_logit[246][t]->erase_contig(this);
  _mem_logit[247][t]->erase_contig(this);
  _mem_logit[248][t]->erase_contig(this);
  _mem_logit[249][t]->erase_contig(this);
  _mem_logit[24][t]->erase_contig(this);
  _mem_logit[250][t]->erase_contig(this);
  _mem_logit[251][t]->erase_contig(this);
  _mem_logit[252][t]->erase_contig(this);
  _mem_logit[253][t]->erase_contig(this);
  _mem_logit[254][t]->erase_contig(this);
  _mem_logit[255][t]->erase_contig(this);
  _mem_logit[256][t]->erase_contig(this);
  _mem_logit[257][t]->erase_contig(this);
  _mem_logit[258][t]->erase_contig(this);
  _mem_logit[259][t]->erase_contig(this);
  _mem_logit[25][t]->erase_contig(this);
  _mem_logit[260][t]->erase_contig(this);
  _mem_logit[261][t]->erase_contig(this);
  _mem_logit[262][t]->erase_contig(this);
  _mem_logit[263][t]->erase_contig(this);
  _mem_logit[264][t]->erase_contig(this);
  _mem_logit[265][t]->erase_contig(this);
  _mem_logit[266][t]->erase_contig(this);
  _mem_logit[267][t]->erase_contig(this);
  _mem_logit[268][t]->erase_contig(this);
  _mem_logit[269][t]->erase_contig(this);
  _mem_logit[26][t]->erase_contig(this);
  _mem_logit[270][t]->erase_contig(this);
  _mem_logit[271][t]->erase_contig(this);
  _mem_logit[272][t]->erase_contig(this);
  _mem_logit[273][t]->erase_contig(this);
  _mem_logit[274][t]->erase_contig(this);
  _mem_logit[275][t]->erase_contig(this);
  _mem_logit[276][t]->erase_contig(this);
  _mem_logit[27][t]->erase_contig(this);
  _mem_logit[28][t]->erase_contig(this);
  _mem_logit[29][t]->erase_contig(this);
  _mem_logit[2][t]->erase_contig(this);
  _mem_logit[30][t]->erase_contig(this);
  _mem_logit[31][t]->erase_contig(this);
  _mem_logit[32][t]->erase_contig(this);
  _mem_logit[33][t]->erase_contig(this);
  _mem_logit[34][t]->erase_contig(this);
  _mem_logit[35][t]->erase_contig(this);
  _mem_logit[36][t]->erase_contig(this);
  _mem_logit[37][t]->erase_contig(this);
  _mem_logit[38][t]->erase_contig(this);
  _mem_logit[39][t]->erase_contig(this);
  _mem_logit[3][t]->erase_contig(this);
  _mem_logit[40][t]->erase_contig(this);
  _mem_logit[41][t]->erase_contig(this);
  _mem_logit[42][t]->erase_contig(this);
  _mem_logit[43][t]->erase_contig(this);
  _mem_logit[44][t]->erase_contig(this);
  _mem_logit[45][t]->erase_contig(this);
  _mem_logit[46][t]->erase_contig(this);
  _mem_logit[47][t]->erase_contig(this);
  _mem_logit[48][t]->erase_contig(this);
  _mem_logit[49][t]->erase_contig(this);
  _mem_logit[4][t]->erase_contig(this);
  _mem_logit[50][t]->erase_contig(this);
  _mem_logit[51][t]->erase_contig(this);
  _mem_logit[52][t]->erase_contig(this);
  _mem_logit[53][t]->erase_contig(this);
  _mem_logit[54][t]->erase_contig(this);
  _mem_logit[55][t]->erase_contig(this);
  _mem_logit[56][t]->erase_contig(this);
  _mem_logit[57][t]->erase_contig(this);
  _mem_logit[58][t]->erase_contig(this);
  _mem_logit[59][t]->erase_contig(this);
  _mem_logit[5][t]->erase_contig(this);
  _mem_logit[60][t]->erase_contig(this);
  _mem_logit[61][t]->erase_contig(this);
  _mem_logit[62][t]->erase_contig(this);
  _mem_logit[63][t]->erase_contig(this);
  _mem_logit[64][t]->erase_contig(this);
  _mem_logit[65][t]->erase_contig(this);
  _mem_logit[66][t]->erase_contig(this);
  _mem_logit[67][t]->erase_contig(this);
  _mem_logit[68][t]->erase_contig(this);
  _mem_logit[69][t]->erase_contig(this);
  _mem_logit[6][t]->erase_contig(this);
  _mem_logit[70][t]->erase_contig(this);
  _mem_logit[71][t]->erase_contig(this);
  _mem_logit[72][t]->erase_contig(this);
  _mem_logit[73][t]->erase_contig(this);
  _mem_logit[74][t]->erase_contig(this);
  _mem_logit[75][t]->erase_contig(this);
  _mem_logit[76][t]->erase_contig(this);
  _mem_logit[77][t]->erase_contig(this);
  _mem_logit[78][t]->erase_contig(this);
  _mem_logit[79][t]->erase_contig(this);
  _mem_logit[7][t]->erase_contig(this);
  _mem_logit[80][t]->erase_contig(this);
  _mem_logit[81][t]->erase_contig(this);
  _mem_logit[82][t]->erase_contig(this);
  _mem_logit[83][t]->erase_contig(this);
  _mem_logit[84][t]->erase_contig(this);
  _mem_logit[85][t]->erase_contig(this);
  _mem_logit[86][t]->erase_contig(this);
  _mem_logit[87][t]->erase_contig(this);
  _mem_logit[88][t]->erase_contig(this);
  _mem_logit[89][t]->erase_contig(this);
  _mem_logit[8][t]->erase_contig(this);
  _mem_logit[90][t]->erase_contig(this);
  _mem_logit[91][t]->erase_contig(this);
  _mem_logit[92][t]->erase_contig(this);
  _mem_logit[93][t]->erase_contig(this);
  _mem_logit[94][t]->erase_contig(this);
  _mem_logit[95][t]->erase_contig(this);
  _mem_logit[96][t]->erase_contig(this);
  _mem_logit[97][t]->erase_contig(this);
  _mem_logit[98][t]->erase_contig(this);
  _mem_logit[99][t]->erase_contig(this);
  _mem_logit[9][t]->erase_contig(this);
  _mem_logit[0][t]->erase_child(this);
  _mem_logit[100][t]->erase_child(this);
  _mem_logit[101][t]->erase_child(this);
  _mem_logit[102][t]->erase_child(this);
  _mem_logit[103][t]->erase_child(this);
  _mem_logit[104][t]->erase_child(this);
  _mem_logit[105][t]->erase_child(this);
  _mem_logit[106][t]->erase_child(this);
  _mem_logit[107][t]->erase_child(this);
  _mem_logit[108][t]->erase_child(this);
  _mem_logit[109][t]->erase_child(this);
  _mem_logit[10][t]->erase_child(this);
  _mem_logit[110][t]->erase_child(this);
  _mem_logit[111][t]->erase_child(this);
  _mem_logit[112][t]->erase_child(this);
  _mem_logit[113][t]->erase_child(this);
  _mem_logit[114][t]->erase_child(this);
  _mem_logit[115][t]->erase_child(this);
  _mem_logit[116][t]->erase_child(this);
  _mem_logit[117][t]->erase_child(this);
  _mem_logit[118][t]->erase_child(this);
  _mem_logit[119][t]->erase_child(this);
  _mem_logit[11][t]->erase_child(this);
  _mem_logit[120][t]->erase_child(this);
  _mem_logit[121][t]->erase_child(this);
  _mem_logit[122][t]->erase_child(this);
  _mem_logit[123][t]->erase_child(this);
  _mem_logit[124][t]->erase_child(this);
  _mem_logit[125][t]->erase_child(this);
  _mem_logit[126][t]->erase_child(this);
  _mem_logit[127][t]->erase_child(this);
  _mem_logit[128][t]->erase_child(this);
  _mem_logit[129][t]->erase_child(this);
  _mem_logit[12][t]->erase_child(this);
  _mem_logit[130][t]->erase_child(this);
  _mem_logit[131][t]->erase_child(this);
  _mem_logit[132][t]->erase_child(this);
  _mem_logit[133][t]->erase_child(this);
  _mem_logit[134][t]->erase_child(this);
  _mem_logit[135][t]->erase_child(this);
  _mem_logit[136][t]->erase_child(this);
  _mem_logit[137][t]->erase_child(this);
  _mem_logit[138][t]->erase_child(this);
  _mem_logit[139][t]->erase_child(this);
  _mem_logit[13][t]->erase_child(this);
  _mem_logit[140][t]->erase_child(this);
  _mem_logit[141][t]->erase_child(this);
  _mem_logit[142][t]->erase_child(this);
  _mem_logit[143][t]->erase_child(this);
  _mem_logit[144][t]->erase_child(this);
  _mem_logit[145][t]->erase_child(this);
  _mem_logit[146][t]->erase_child(this);
  _mem_logit[147][t]->erase_child(this);
  _mem_logit[148][t]->erase_child(this);
  _mem_logit[149][t]->erase_child(this);
  _mem_logit[14][t]->erase_child(this);
  _mem_logit[150][t]->erase_child(this);
  _mem_logit[151][t]->erase_child(this);
  _mem_logit[152][t]->erase_child(this);
  _mem_logit[153][t]->erase_child(this);
  _mem_logit[154][t]->erase_child(this);
  _mem_logit[155][t]->erase_child(this);
  _mem_logit[156][t]->erase_child(this);
  _mem_logit[157][t]->erase_child(this);
  _mem_logit[158][t]->erase_child(this);
  _mem_logit[159][t]->erase_child(this);
  _mem_logit[15][t]->erase_child(this);
  _mem_logit[160][t]->erase_child(this);
  _mem_logit[161][t]->erase_child(this);
  _mem_logit[162][t]->erase_child(this);
  _mem_logit[163][t]->erase_child(this);
  _mem_logit[164][t]->erase_child(this);
  _mem_logit[165][t]->erase_child(this);
  _mem_logit[166][t]->erase_child(this);
  _mem_logit[167][t]->erase_child(this);
  _mem_logit[168][t]->erase_child(this);
  _mem_logit[169][t]->erase_child(this);
  _mem_logit[16][t]->erase_child(this);
  _mem_logit[170][t]->erase_child(this);
  _mem_logit[171][t]->erase_child(this);
  _mem_logit[172][t]->erase_child(this);
  _mem_logit[173][t]->erase_child(this);
  _mem_logit[174][t]->erase_child(this);
  _mem_logit[175][t]->erase_child(this);
  _mem_logit[176][t]->erase_child(this);
  _mem_logit[177][t]->erase_child(this);
  _mem_logit[178][t]->erase_child(this);
  _mem_logit[179][t]->erase_child(this);
  _mem_logit[17][t]->erase_child(this);
  _mem_logit[180][t]->erase_child(this);
  _mem_logit[181][t]->erase_child(this);
  _mem_logit[182][t]->erase_child(this);
  _mem_logit[183][t]->erase_child(this);
  _mem_logit[184][t]->erase_child(this);
  _mem_logit[185][t]->erase_child(this);
  _mem_logit[186][t]->erase_child(this);
  _mem_logit[187][t]->erase_child(this);
  _mem_logit[188][t]->erase_child(this);
  _mem_logit[189][t]->erase_child(this);
  _mem_logit[18][t]->erase_child(this);
  _mem_logit[190][t]->erase_child(this);
  _mem_logit[191][t]->erase_child(this);
  _mem_logit[192][t]->erase_child(this);
  _mem_logit[193][t]->erase_child(this);
  _mem_logit[194][t]->erase_child(this);
  _mem_logit[195][t]->erase_child(this);
  _mem_logit[196][t]->erase_child(this);
  _mem_logit[197][t]->erase_child(this);
  _mem_logit[198][t]->erase_child(this);
  _mem_logit[199][t]->erase_child(this);
  _mem_logit[19][t]->erase_child(this);
  _mem_logit[1][t]->erase_child(this);
  _mem_logit[200][t]->erase_child(this);
  _mem_logit[201][t]->erase_child(this);
  _mem_logit[202][t]->erase_child(this);
  _mem_logit[203][t]->erase_child(this);
  _mem_logit[204][t]->erase_child(this);
  _mem_logit[205][t]->erase_child(this);
  _mem_logit[206][t]->erase_child(this);
  _mem_logit[207][t]->erase_child(this);
  _mem_logit[208][t]->erase_child(this);
  _mem_logit[209][t]->erase_child(this);
  _mem_logit[20][t]->erase_child(this);
  _mem_logit[210][t]->erase_child(this);
  _mem_logit[211][t]->erase_child(this);
  _mem_logit[212][t]->erase_child(this);
  _mem_logit[213][t]->erase_child(this);
  _mem_logit[214][t]->erase_child(this);
  _mem_logit[215][t]->erase_child(this);
  _mem_logit[216][t]->erase_child(this);
  _mem_logit[217][t]->erase_child(this);
  _mem_logit[218][t]->erase_child(this);
  _mem_logit[219][t]->erase_child(this);
  _mem_logit[21][t]->erase_child(this);
  _mem_logit[220][t]->erase_child(this);
  _mem_logit[221][t]->erase_child(this);
  _mem_logit[222][t]->erase_child(this);
  _mem_logit[223][t]->erase_child(this);
  _mem_logit[224][t]->erase_child(this);
  _mem_logit[225][t]->erase_child(this);
  _mem_logit[226][t]->erase_child(this);
  _mem_logit[227][t]->erase_child(this);
  _mem_logit[228][t]->erase_child(this);
  _mem_logit[229][t]->erase_child(this);
  _mem_logit[22][t]->erase_child(this);
  _mem_logit[230][t]->erase_child(this);
  _mem_logit[231][t]->erase_child(this);
  _mem_logit[232][t]->erase_child(this);
  _mem_logit[233][t]->erase_child(this);
  _mem_logit[234][t]->erase_child(this);
  _mem_logit[235][t]->erase_child(this);
  _mem_logit[236][t]->erase_child(this);
  _mem_logit[237][t]->erase_child(this);
  _mem_logit[238][t]->erase_child(this);
  _mem_logit[239][t]->erase_child(this);
  _mem_logit[23][t]->erase_child(this);
  _mem_logit[240][t]->erase_child(this);
  _mem_logit[241][t]->erase_child(this);
  _mem_logit[242][t]->erase_child(this);
  _mem_logit[243][t]->erase_child(this);
  _mem_logit[244][t]->erase_child(this);
  _mem_logit[245][t]->erase_child(this);
  _mem_logit[246][t]->erase_child(this);
  _mem_logit[247][t]->erase_child(this);
  _mem_logit[248][t]->erase_child(this);
  _mem_logit[249][t]->erase_child(this);
  _mem_logit[24][t]->erase_child(this);
  _mem_logit[250][t]->erase_child(this);
  _mem_logit[251][t]->erase_child(this);
  _mem_logit[252][t]->erase_child(this);
  _mem_logit[253][t]->erase_child(this);
  _mem_logit[254][t]->erase_child(this);
  _mem_logit[255][t]->erase_child(this);
  _mem_logit[256][t]->erase_child(this);
  _mem_logit[257][t]->erase_child(this);
  _mem_logit[258][t]->erase_child(this);
  _mem_logit[259][t]->erase_child(this);
  _mem_logit[25][t]->erase_child(this);
  _mem_logit[260][t]->erase_child(this);
  _mem_logit[261][t]->erase_child(this);
  _mem_logit[262][t]->erase_child(this);
  _mem_logit[263][t]->erase_child(this);
  _mem_logit[264][t]->erase_child(this);
  _mem_logit[265][t]->erase_child(this);
  _mem_logit[266][t]->erase_child(this);
  _mem_logit[267][t]->erase_child(this);
  _mem_logit[268][t]->erase_child(this);
  _mem_logit[269][t]->erase_child(this);
  _mem_logit[26][t]->erase_child(this);
  _mem_logit[270][t]->erase_child(this);
  _mem_logit[271][t]->erase_child(this);
  _mem_logit[272][t]->erase_child(this);
  _mem_logit[273][t]->erase_child(this);
  _mem_logit[274][t]->erase_child(this);
  _mem_logit[275][t]->erase_child(this);
  _mem_logit[276][t]->erase_child(this);
  _mem_logit[27][t]->erase_child(this);
  _mem_logit[28][t]->erase_child(this);
  _mem_logit[29][t]->erase_child(this);
  _mem_logit[2][t]->erase_child(this);
  _mem_logit[30][t]->erase_child(this);
  _mem_logit[31][t]->erase_child(this);
  _mem_logit[32][t]->erase_child(this);
  _mem_logit[33][t]->erase_child(this);
  _mem_logit[34][t]->erase_child(this);
  _mem_logit[35][t]->erase_child(this);
  _mem_logit[36][t]->erase_child(this);
  _mem_logit[37][t]->erase_child(this);
  _mem_logit[38][t]->erase_child(this);
  _mem_logit[39][t]->erase_child(this);
  _mem_logit[3][t]->erase_child(this);
  _mem_logit[40][t]->erase_child(this);
  _mem_logit[41][t]->erase_child(this);
  _mem_logit[42][t]->erase_child(this);
  _mem_logit[43][t]->erase_child(this);
  _mem_logit[44][t]->erase_child(this);
  _mem_logit[45][t]->erase_child(this);
  _mem_logit[46][t]->erase_child(this);
  _mem_logit[47][t]->erase_child(this);
  _mem_logit[48][t]->erase_child(this);
  _mem_logit[49][t]->erase_child(this);
  _mem_logit[4][t]->erase_child(this);
  _mem_logit[50][t]->erase_child(this);
  _mem_logit[51][t]->erase_child(this);
  _mem_logit[52][t]->erase_child(this);
  _mem_logit[53][t]->erase_child(this);
  _mem_logit[54][t]->erase_child(this);
  _mem_logit[55][t]->erase_child(this);
  _mem_logit[56][t]->erase_child(this);
  _mem_logit[57][t]->erase_child(this);
  _mem_logit[58][t]->erase_child(this);
  _mem_logit[59][t]->erase_child(this);
  _mem_logit[5][t]->erase_child(this);
  _mem_logit[60][t]->erase_child(this);
  _mem_logit[61][t]->erase_child(this);
  _mem_logit[62][t]->erase_child(this);
  _mem_logit[63][t]->erase_child(this);
  _mem_logit[64][t]->erase_child(this);
  _mem_logit[65][t]->erase_child(this);
  _mem_logit[66][t]->erase_child(this);
  _mem_logit[67][t]->erase_child(this);
  _mem_logit[68][t]->erase_child(this);
  _mem_logit[69][t]->erase_child(this);
  _mem_logit[6][t]->erase_child(this);
  _mem_logit[70][t]->erase_child(this);
  _mem_logit[71][t]->erase_child(this);
  _mem_logit[72][t]->erase_child(this);
  _mem_logit[73][t]->erase_child(this);
  _mem_logit[74][t]->erase_child(this);
  _mem_logit[75][t]->erase_child(this);
  _mem_logit[76][t]->erase_child(this);
  _mem_logit[77][t]->erase_child(this);
  _mem_logit[78][t]->erase_child(this);
  _mem_logit[79][t]->erase_child(this);
  _mem_logit[7][t]->erase_child(this);
  _mem_logit[80][t]->erase_child(this);
  _mem_logit[81][t]->erase_child(this);
  _mem_logit[82][t]->erase_child(this);
  _mem_logit[83][t]->erase_child(this);
  _mem_logit[84][t]->erase_child(this);
  _mem_logit[85][t]->erase_child(this);
  _mem_logit[86][t]->erase_child(this);
  _mem_logit[87][t]->erase_child(this);
  _mem_logit[88][t]->erase_child(this);
  _mem_logit[89][t]->erase_child(this);
  _mem_logit[8][t]->erase_child(this);
  _mem_logit[90][t]->erase_child(this);
  _mem_logit[91][t]->erase_child(this);
  _mem_logit[92][t]->erase_child(this);
  _mem_logit[93][t]->erase_child(this);
  _mem_logit[94][t]->erase_child(this);
  _mem_logit[95][t]->erase_child(this);
  _mem_logit[96][t]->erase_child(this);
  _mem_logit[97][t]->erase_child(this);
  _mem_logit[98][t]->erase_child(this);
  _mem_logit[99][t]->erase_child(this);
  _mem_logit[9][t]->erase_child(this);
}
void _Var_region_rate::mcmc_resample()
{
  mh_parent_resample_arg(this);
}
void sample()
{
  for (_cur_loop=1;_cur_loop<=_TOT_LOOP;_cur_loop++)
  {
    mcmc_sample_single_iter();
    _eval_query();
  }

}

}
int main()
{
  std::chrono::time_point<std::chrono::system_clock> __start_time = std::chrono::system_clock::now();
  swift::_init_storage();
  swift::_init_world();
  std::chrono::duration<double> __elapsed_seconds = std::chrono::system_clock::now()-__start_time;
  printf("\ninit time: %fs\n",__elapsed_seconds.count());
  __start_time=std::chrono::system_clock::now();
  swift::sample();
  __elapsed_seconds=std::chrono::system_clock::now()-__start_time;
  printf("\nsample time: %fs (#iter = %d)\n",__elapsed_seconds.count(),8000000);
  swift::_print_answer();
  swift::_garbage_collection();
}

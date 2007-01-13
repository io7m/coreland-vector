struct multsc_test {
  float va[4];
  float vr[4];
  float sc;
  unsigned int sz;
  char x[vec_align(sizeof(float) * 8 + sizeof(float) + sizeof(unsigned int))];
};

struct multsc_test tests[] = {
  /* GENERATION/multsc_gen.c */
  {
    {0.000000, 0.000000, 0.000000, 0.000000},
    {0.000000, 0.000000, 0.000000, 0.000000},
    0.000000,
    4,
    {0},
  },
  {
    {1.197484, -12.030043, 0.000000, 0.000000},
    {-1.973232, 19.823283, -0.000000, -0.000000},
    -1.647815,
    2,
    {0},
  },
  {
    {-15.896667, 0.936321, 0.000000, 0.000000},
    {-124.719298, 7.346023, 0.000000, 0.000000},
    7.845626,
    2,
    {0},
  },
  {
    {6.410494, 13.435028, 0.000000, 0.000000},
    {9.698911, 20.326848, 0.000000, 0.000000},
    1.512974,
    2,
    {0},
  },
  {
    {3.685250, -2.259036, 0.000000, 0.000000},
    {-429.068378, 263.016347, -0.000000, -0.000000},
    -116.428574,
    2,
    {0},
  },
  {
    {7.788764, -11.035041, 0.000000, 0.000000},
    {-217.241607, 307.785678, -0.000000, -0.000000},
    -27.891666,
    2,
    {0},
  },
  {
    {5.435669, -1.621488, 0.000000, 0.000000},
    {-7.645005, 2.280544, -0.000000, -0.000000},
    -1.406452,
    2,
    {0},
  },
  {
    {5.157534, -8.384083, 0.000000, 0.000000},
    {5.147500, -8.367772, 0.000000, 0.000000},
    0.998055,
    2,
    {0},
  },
  {
    {-6.062500, -7.109445, 0.000000, 0.000000},
    {32.804030, 38.469023, -0.000000, -0.000000},
    -5.410974,
    2,
    {0},
  },
  {
    {8.440217, 12.310850, 0.000000, 0.000000},
    {-120.026464, -175.069884, -0.000000, -0.000000},
    -14.220779,
    2,
    {0},
  },
  {
    {-18.771429, -4.075047, 13.954704, 0.000000},
    {192.319339, 41.750170, -142.970442, -0.000000},
    -10.245322,
    3,
    {0},
  },
  {
    {12.593407, 52.065933, 0.220382, 0.000000},
    {-18.926933, -78.251139, -0.331218, -0.000000},
    -1.502924,
    3,
    {0},
  },
  {
    {0.544919, 12.105263, -4.662447, 0.000000},
    {-0.762887, -16.947368, 6.527426, -0.000000},
    -1.400000,
    3,
    {0},
  },
  {
    {-4.602410, 6.376910, -16.705883, 0.000000},
    {-9.764043, 13.528658, -35.441643, 0.000000},
    2.121507,
    3,
    {0},
  },
  {
    {-8.179105, 5.221143, -12.685082, 0.000000},
    {39.103825, -24.961983, 60.646643, -0.000000},
    -4.780942,
    3,
    {0},
  },
  {
    {-23.336683, 4.115862, -6.452830, 0.000000},
    {-73.749262, 13.007066, -20.392421, 0.000000},
    3.160229,
    3,
    {0},
  },
  {
    {7.546358, 2.775701, 3.971264, 0.000000},
    {-68.825206, -25.315285, -36.219207, -0.000000},
    -9.120321,
    3,
    {0},
  },
  {
    {-2.604859, 3.476327, -10.955556, 0.000000},
    {11.554376, -15.419946, 48.595564, -0.000000},
    -4.435700,
    3,
    {0},
  },
  {
    {6.323144, 1.117202, 18.153111, 0.000000},
    {37.282483, 6.587241, 107.034261, 0.000000},
    5.896194,
    3,
    {0},
  },
  {
    {8.554672, -5.331989, -17.817797, 0.000000},
    {27.219412, -16.965421, -56.692991, 0.000000},
    3.181818,
    3,
    {0},
  },
  {
    {12.378378, 0.767263, 4.700730, -10.089947},
    {-125.150390, -7.757342, -47.526273, 102.013428},
    -10.110403,
    4,
    {0},
  },
  {
    {-3.504608, 21.531532, -1.660661, -7.742105},
    {-17.865230, 109.759991, -8.465449, -39.466463},
    5.097640,
    4,
    {0},
  },
  {
    {4.241481, -1.608611, 4.353282, -7.541741},
    {98.232706, -37.255419, 100.822010, -174.666718},
    23.160000,
    4,
    {0},
  },
  {
    {-2.531595, -4.387324, -29.776316, -5.294209},
    {-0.335109, -0.580753, -3.941510, -0.700798},
    0.132371,
    4,
    {0},
  },
  {
    {-2.688084, -7.221428, -6.516854, 5.298701},
    {39.356767, 105.730350, 95.414536, -77.579325},
    -14.641196,
    4,
    {0},
  },
  {
    {-5.284595, -9.002193, 6.560158, 0.139442},
    {29.864678, 50.873829, -37.073225, -0.788026},
    -5.651270,
    4,
    {0},
  },
  {
    {7.637931, 34.689655, 7.946524, -35.916668},
    {-414.790571, -1883.879570, -431.549243, 1950.514537},
    -54.306667,
    4,
    {0},
  },
  {
    {-3.125378, 2.290735, -19.649403, 1.825527},
    {-0.692048, 0.507234, -4.350939, 0.404224},
    0.221429,
    4,
    {0},
  },
  {
    {8.799603, 6.842975, 4.385631, -5.970266},
    {-62.385565, -48.513876, -31.092315, 42.326726},
    -7.089588,
    4,
    {0},
  },
  {
    {22.155556, 0.237052, -13.025568, -0.594187},
    {-68.620360, -0.734199, 40.342891, 1.840322},
    -3.097208,
    4,
    {0},
  },
};
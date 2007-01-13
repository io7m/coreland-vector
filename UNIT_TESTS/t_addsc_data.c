struct addsc_test {
  float va[4];
  float vr[4];
  float sc;
  unsigned int sz;
  char x[vec_align(sizeof(float) * 8 + sizeof(float) + sizeof(unsigned int))];
};

struct addsc_test tests[] = {
  /* GENERATION/addsc_gen.c */
  {
    {0.000000, 0.000000, 0.000000, 0.000000},
    {0.000000, 0.000000, 0.000000, 0.000000},
    0.000000,
    4,
    {0},
  },
  {
    {-5.058355, 6.520599, 0.000000, 0.000000},
    {-10.065031, 1.513924, -5.006676, -5.006676},
    -5.006676,
    2,
    {0},
  },
  {
    {-5.966805, -5.505814, 0.000000, 0.000000},
    {-1.969215, -1.508224, 3.997590, 3.997590},
    3.997590,
    2,
    {0},
  },
  {
    {13.127071, 11.363636, 0.000000, 0.000000},
    {5.378624, 3.615189, -7.748447, -7.748447},
    -7.748447,
    2,
    {0},
  },
  {
    {5.884615, -4.644128, 0.000000, 0.000000},
    {14.024309, 3.495565, 8.139693, 8.139693},
    8.139693,
    2,
    {0},
  },
  {
    {3.457955, 13.376021, 0.000000, 0.000000},
    {-15.079546, -5.161479, -18.537500, -18.537500},
    -18.537500,
    2,
    {0},
  },
  {
    {3.766949, 16.708662, 0.000000, 0.000000},
    {-6.372836, 6.568877, -10.139785, -10.139785},
    -10.139785,
    2,
    {0},
  },
  {
    {11.954301, 2.783370, 0.000000, 0.000000},
    {14.414395, 5.243464, 2.460094, 2.460094},
    2.460094,
    2,
    {0},
  },
  {
    {-9.191588, -7.283298, 0.000000, 0.000000},
    {-21.471282, -19.562992, -12.279694, -12.279694},
    -12.279694,
    2,
    {0},
  },
  {
    {-6.443099, 1.145215, 0.000000, 0.000000},
    {-118.384277, -110.795963, -111.941177, -111.941177},
    -111.941177,
    2,
    {0},
  },
  {
    {-3.317961, 5.417657, -6.168880, 0.000000},
    {3.203702, 11.939321, 0.352783, 6.521664},
    6.521664,
    3,
    {0},
  },
  {
    {4.791536, 3.798870, -15.407018, 0.000000},
    {20.544622, 19.551956, 0.346068, 15.753086},
    15.753086,
    3,
    {0},
  },
  {
    {-1.948617, 2.654321, 10.302500, 0.000000},
    {-7.265495, -2.662558, 4.985621, -5.316879},
    -5.316879,
    3,
    {0},
  },
  {
    {0.152416, 6.326705, -25.988506, 0.000000},
    {0.493943, 6.668231, -25.646980, 0.341527},
    0.341527,
    3,
    {0},
  },
  {
    {-927.599976, -1.817844, 12.477477, 0.000000},
    {-925.899358, -0.117227, 14.178094, 1.700617},
    1.700617,
    3,
    {0},
  },
  {
    {-9.307693, -6.030637, -0.025974, 0.000000},
    {-13.502621, -10.225566, -4.220903, -4.194929},
    -4.194929,
    3,
    {0},
  },
  {
    {3.657603, -6.119718, -47.104763, 0.000000},
    {-5.273431, -15.050752, -56.035797, -8.931034},
    -8.931034,
    3,
    {0},
  },
  {
    {-9.489933, -0.189369, -1.914016, 0.000000},
    {-34.776600, -25.476036, -27.200683, -25.286667},
    -25.286667,
    3,
    {0},
  },
  {
    {55.088890, -3.782432, 6.820144, 0.000000},
    {52.782020, -6.089303, 4.513273, -2.306870},
    -2.306870,
    3,
    {0},
  },
  {
    {0.753994, 3.776087, 5.671111, 0.000000},
    {5.195335, 8.217428, 10.112452, 4.441341},
    4.441341,
    3,
    {0},
  },
  {
    {-4.468284, 3.038889, -4.909091, 113.125000},
    {-40.082320, -32.575148, -40.523128, 77.510963},
    -35.614037,
    4,
    {0},
  },
  {
    {4.674318, 4.589670, -4.759140, -8.728880},
    {11.137661, 11.053013, 1.704203, -2.265537},
    6.463343,
    4,
    {0},
  },
  {
    {3.342282, 3.284271, 2.397561, 32.068626},
    {11.608691, 11.550680, 10.663970, 40.335035},
    8.266409,
    4,
    {0},
  },
  {
    {4.913876, -0.171548, -29.723404, 11.918288},
    {4.105159, -0.980265, -30.532121, 11.109572},
    -0.808717,
    4,
    {0},
  },
  {
    {8.992208, -5.315676, -3.942598, -17.247747},
    {4.311828, -9.996056, -8.622978, -21.928127},
    -4.680380,
    4,
    {0},
  },
  {
    {6.315934, -3.538377, -4.883295, 0.445196},
    {19.299033, 9.444722, 8.099804, 13.428295},
    12.983099,
    4,
    {0},
  },
  {
    {0.803738, 280.133331, -2.642565, -10.560510},
    {37.081517, 316.411110, 33.635214, 25.717269},
    36.277779,
    4,
    {0},
  },
  {
    {390.222229, 5.937662, -4.174234, -1.229290},
    {397.185452, 12.900885, 2.788988, 5.733933},
    6.963223,
    4,
    {0},
  },
  {
    {-20.011765, -1.747387, -44.430557, -14.666667},
    {-17.030437, 1.233941, -41.449229, -11.685339},
    2.981328,
    4,
    {0},
  },
  {
    {-1.318290, 2.552398, 4.300300, 8.314000},
    {0.679690, 4.550378, 6.298280, 10.311980},
    1.997980,
    4,
    {0},
  },
};
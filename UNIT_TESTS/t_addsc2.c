#include <stdio.h>
#include <math.h>
#include "../vector.h"
#include "t_util.h"

struct addsc_test {
  float va[4];
  float sc;
  float vr[4];
  unsigned int sz;
};

struct addsc_test tests[] = {
  /* tools/addsc_gen.c */
  {
    {0.000000, 0.000000, 0.000000, 0.000000},
    0.000000,
    {0.000000, 0.000000, 0.000000, 0.000000},
    4,
  },
  {
    {-9.064406, 14.652174, 0.000000, 0.000000},
    -3.172333,
    {-12.236739, 11.479841, -3.172333, -3.172333},
    2,
  },
  {
    {-1.577011, -15.128205, 0.000000, 0.000000},
    -2.557692,
    {-4.134704, -17.685898, -2.557692, -2.557692},
    2,
  },
  {
    {0.952818, 18.856382, 0.000000, 0.000000},
    34.953705,
    {35.906523, 53.810087, 34.953705, 34.953705},
    2,
  },
  {
    {-0.047820, 5.608333, 0.000000, 0.000000},
    5.516210,
    {5.468390, 11.124543, 5.516210, 5.516210},
    2,
  },
  {
    {4.056667, 26.524590, 0.000000, 0.000000},
    10.539823,
    {14.596489, 37.064412, 10.539823, 10.539823},
    2,
  },
  {
    {2.216617, 39.377777, 0.000000, 0.000000},
    9.810606,
    {12.027223, 49.188383, 9.810606, 9.810606},
    2,
  },
  {
    {2.968586, -3.756757, 0.000000, 0.000000},
    4.661856,
    {7.630442, 0.905099, 4.661856, 4.661856},
    2,
  },
  {
    {-14.150485, 5.598393, 0.000000, 0.000000},
    -3.636508,
    {-17.786993, 1.961885, -3.636508, -3.636508},
    2,
  },
  {
    {-6.335249, 5.387574, 0.000000, 0.000000},
    -4.292350,
    {-10.627599, 1.095224, -4.292350, -4.292350},
    2,
  },
  {
    {-5.074942, -4.136223, -0.609756, 0.000000},
    27.860214,
    {22.785273, 23.723991, 27.250458, 27.860214},
    3,
  },
  {
    {-8.132969, 3.444672, 25.568306, 0.000000},
    -8.078203,
    {-16.211172, -4.633531, 17.490103, -8.078203},
    3,
  },
  {
    {9.407674, 6.931035, -466.500000, 0.000000},
    8.102981,
    {17.510654, 15.034015, -458.397019, 8.102981},
    3,
  },
  {
    {-1.135108, 4.393275, 2.316384, 0.000000},
    -0.599078,
    {-1.734186, 3.794196, 1.717306, -0.599078},
    3,
  },
  {
    {35.260868, -4.830952, 0.580974, 0.000000},
    3.751913,
    {39.012781, -1.079040, 4.332887, 3.751913},
    3,
  },
  {
    {89.857140, 9.081545, -60.158535, 0.000000},
    2.056242,
    {91.913381, 11.137786, -58.102293, 2.056242},
    3,
  },
  {
    {-9.508772, 2.848101, -9.812500, 0.000000},
    5.844575,
    {-3.664197, 8.692676, -3.967925, 5.844575},
    3,
  },
  {
    {-1.326531, 2.622623, -29.533333, 0.000000},
    0.202247,
    {-1.124283, 2.824870, -29.331086, 0.202247},
    3,
  },
  {
    {-13.151376, 7.380342, 2.740481, 0.000000},
    5.853557,
    {-7.297819, 13.233899, 8.594038, 5.853557},
    3,
  },
  {
    {-2.137681, -2.469990, 21.695999, 0.000000},
    -30.718309,
    {-32.855991, -33.188299, -9.022310, -30.718309},
    3,
  },
  {
    {-7.510870, 22.517647, 6.571621, -20.258621},
    -6.145833,
    {-13.656703, 16.371813, 0.425788, -26.404455},
    4,
  },
  {
    {-8.225447, -2.709677, -2.609606, -2.120930},
    4.907463,
    {-3.317984, 2.197785, 2.297857, 2.786532},
    4,
  },
  {
    {-11.100818, -3.325581, 0.027467, -4.410256},
    -23.604395,
    {-34.705213, -26.929976, -23.576928, -28.014651},
    4,
  },
  {
    {-0.342857, -4.739653, -2.064208, -4.123308},
    9.164038,
    {8.821181, 4.424385, 7.099830, 5.040730},
    4,
  },
  {
    {2.254151, 6.024476, -0.285405, 15.055046},
    5.575000,
    {7.829150, 11.599475, 5.289594, 20.630046},
    4,
  },
  {
    {-4.516755, 1.023404, -10.395270, -11.504399},
    -5.768229,
    {-10.284984, -4.744825, -16.163499, -17.272628},
    4,
  },
  {
    {-1.438105, -5.761974, 5.950644, 7.944231},
    26.156250,
    {24.718145, 20.394276, 32.106894, 34.100481},
    4,
  },
  {
    {-7.301547, 6.578073, 7.959217, -4.390244},
    22.188313,
    {14.886766, 28.766386, 30.147530, 17.798069},
    4,
  },
  {
    {-7.447712, 2.620770, -13.750000, 7.143678},
    3.269297,
    {-4.178416, 5.890067, -10.480703, 10.412975},
    4,
  },
  {
    {1.680934, 4.558568, 3.785475, 8.410335},
    -1.881745,
    {-0.200811, 2.676823, 1.903730, 6.528589},
    4,
  },
};

int main()
{
  float tmp[4] = {0.0, 0.0, 0.0, 0.0};
  unsigned int ind;
  unsigned int jnd;

  for (ind = 0; ind < sizeof(tests) / sizeof(struct addsc_test); ++ind) {
    switch (tests[ind].sz) {
      case 4:
        vec_addsc4fx(tests[ind].va, tmp, tests[ind].sc);
        break;
      case 3:
        vec_addsc3fx(tests[ind].va, tmp, tests[ind].sc);
        break;
      case 2:
        vec_addsc2fx(tests[ind].va, tmp, tests[ind].sc);
        break;
      default:
        printf("error: ended up in default switch statement\n");
        return 2;
    }
    for (jnd = 0; jnd < tests[ind].sz; ++jnd) {
      if (!approx_equalf(tests[ind].vr[jnd], tmp[jnd], APPROX_MAX_ERROR)) {
        printf("fail: [%u] vr[%u] %f != va[%u] %f\n",
                ind, jnd, tests[ind].vr[jnd], jnd, tmp[jnd]);
      }
      printf("[%u] vr[%u] %f ~ va[%u] %f\n",
              ind, jnd, tests[ind].vr[jnd], jnd, tmp[jnd]);
    }
    printf("--\n");
  }

  return 0;
} 

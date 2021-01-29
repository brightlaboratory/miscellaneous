
LIBXSMM_LIB=<set the path>
icc -O3 -I${LIBXSMM_LIB}/include -fopenmp -L${LIBXSMM_LIB}/lib matmul.c -o matmul -lxsmm -lxsmmext -ldl -lm

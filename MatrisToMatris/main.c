#include"stdio.h"
#include"stdlib.h"
#include"mpi.h"
#define N 1500
#define X 1500
#define Y 1500
int main(int argc, char **argv)
{
	int size, rank, sum = 0, i, j, k;
	int **matrix1;  //declared matrix1[X][N]
	int **matrix2; //declare matrix2[N][Y]
	int **mat_res; //resultant matrix become mat_res[X][Y]
	double t1, t2, result;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	/*----------------------------------------------------*/
	//create array of pointers(Rows)
	matrix1 = (int **)malloc(X * sizeof(int*));
	matrix2 = (int **)malloc(N * sizeof(int*));
	mat_res = (int **)malloc(X * sizeof(int*));
	/*----------------------------------------------------*/


	/*--------------------------------------------------------------------------------*/
	//allocate memory for each Row pointer
	for (i = 0; i < X; i++)
	{
		matrix1[i] = (int *)malloc(N * sizeof(int));
		mat_res[i] = (int *)malloc(Y * sizeof(int));
	}

	for (i = 0; i < N; i++)
		matrix2[i] = (int *)malloc(Y * sizeof(int));
	/*--------------------------------------------------------------------------------*/

	for (i = 0; i < X; i++)
	{
		for (j = 0; j < N; j++)
		{
			matrix1[i][j] = rand() % 10; //initialize 1 to matrix1 for all processes


		}

	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < Y; j++)
		{
			matrix2[i][j] = rand() % 10;//initialize 2 to matrix2 for all processes


		}

	}
	MPI_Barrier(MPI_COMM_WORLD);
	if (rank == 0)
		t1 = MPI_Wtime();
	for (i = rank; i < X; i = i + size) //divide the task in multiple processes
	{
		for (j = 0; j < Y; j++)
		{
			sum = 0;
			for (k = 0; k < N; k+=50)
			{
				sum = sum + matrix1[i][k] * matrix2[k][j];
   				sum = sum + matrix1[i][k+1] * matrix2[k+1][j];
				sum = sum + matrix1[i][k+2] * matrix2[k+2][j];
				sum = sum + matrix1[i][k+3] * matrix2[k+3][j];
				sum = sum + matrix1[i][k+4] * matrix2[k+4][j];
				sum = sum + matrix1[i][k+5] * matrix2[k+5][j];
				sum = sum + matrix1[i][k+6] * matrix2[k+6][j];
				sum = sum + matrix1[i][k+7] * matrix2[k+7][j];
				sum = sum + matrix1[i][k+8] * matrix2[k+8][j];
				sum = sum + matrix1[i][k+9] * matrix2[k+9][j];
				sum = sum + matrix1[i][k+10] * matrix2[k+10][j];
				sum = sum + matrix1[i][k+11] * matrix2[k+11][j];
				sum = sum + matrix1[i][k+12] * matrix2[k+12][j];
				sum = sum + matrix1[i][k+13] * matrix2[k+13][j];
				sum = sum + matrix1[i][k+14] * matrix2[k+14][j];
				sum = sum + matrix1[i][k+15] * matrix2[k+15][j];
				sum = sum + matrix1[i][k+16] * matrix2[k+16][j];
				sum = sum + matrix1[i][k+17] * matrix2[k+17][j];
				sum = sum + matrix1[i][k+18] * matrix2[k+18][j];
				sum = sum + matrix1[i][k+19] * matrix2[k+19][j];
				sum = sum + matrix1[i][k+20] * matrix2[k+20][j];
				sum = sum + matrix1[i][k+21] * matrix2[k+21][j];
				sum = sum + matrix1[i][k+22] * matrix2[k+22][j];
				sum = sum + matrix1[i][k+23] * matrix2[k+23][j];
				sum = sum + matrix1[i][k+24] * matrix2[k+24][j];
				sum = sum + matrix1[i][k+25] * matrix2[k+25][j];
				sum = sum + matrix1[i][k+26] * matrix2[k+26][j];
				sum = sum + matrix1[i][k+27] * matrix2[k+27][j];
				sum = sum + matrix1[i][k+28] * matrix2[k+28][j];
				sum = sum + matrix1[i][k+29] * matrix2[k+29][j];
				sum = sum + matrix1[i][k+30] * matrix2[k+30][j];
				sum = sum + matrix1[i][k+31] * matrix2[k+31][j];
				sum = sum + matrix1[i][k+32] * matrix2[k+32][j];
				sum = sum + matrix1[i][k+33] * matrix2[k+33][j];
				sum = sum + matrix1[i][k+35] * matrix2[k+34][j];
				sum = sum + matrix1[i][k+36] * matrix2[k+35][j];
				sum = sum + matrix1[i][k+37] * matrix2[k+36][j];
				sum = sum + matrix1[i][k+37] * matrix2[k+37][j];
				sum = sum + matrix1[i][k+38] * matrix2[k+38][j];
				sum = sum + matrix1[i][k+39] * matrix2[k+39][j];
				sum = sum + matrix1[i][k+40] * matrix2[k+40][j];
				sum = sum + matrix1[i][k+41] * matrix2[k+41][j];
				sum = sum + matrix1[i][k+42] * matrix2[k+42][j];
				sum = sum + matrix1[i][k+43] * matrix2[k+43][j];
				sum = sum + matrix1[i][k+44] * matrix2[k+44][j];
				sum = sum + matrix1[i][k+45] * matrix2[k+45][j];
				sum = sum + matrix1[i][k+46] * matrix2[k+46][j];
				sum = sum + matrix1[i][k+47] * matrix2[k+47][j];
				sum = sum + matrix1[i][k+48] * matrix2[k+48][j];
				sum = sum + matrix1[i][k+49] * matrix2[k+49][j];
			}
			mat_res[i][j] = sum;
		}
	}

	if (rank != 0)
	{
		for (i = rank; i < X; i = i + size)
			MPI_Send(&mat_res[i][0], Y, MPI_INT, 0, 10 + i, MPI_COMM_WORLD);//send calculated rows to process with rank 0
	}

	if (rank == 0)
	{
		for (j = 1; j < size; j++)
		{
			for (i = j; i < X; i = i + size)
			{
				MPI_Recv(&mat_res[i][0], Y, MPI_INT, j, 10 + i, MPI_COMM_WORLD, &status);//receive calculated rows from respective process
			}
		}
	}
	MPI_Barrier(MPI_COMM_WORLD);
	if (rank == 0)
		t2 = MPI_Wtime();
	result = t2 - t1;



	if (rank == 0)
		printf("Gecen Sure = %d of %d %f seconds\n", rank, size, result); //time taken

	MPI_Finalize();
	return 0;
}

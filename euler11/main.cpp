#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

typedef vector < vector<int> > mtx;
mtx read_matrix(const char * filename);
void print_matrix(const mtx & M);
int max_HV(mtx myGrid, int adjNumbers);
int max_mainDiag(mtx myGrid, int adjNumbers);
int max_minorDiag(mtx myGrid, int adjNumbers);

int main()
{
    mtx myGrid = read_matrix("grid.txt"); //racs
    if (myGrid.empty() )
    	return -1;
    	
    const int adjNumbers = 4; //szomszedos szamok szama

    print_matrix(myGrid);
    int max1 = max_HV(myGrid, adjNumbers);
    int max2 = max_mainDiag(myGrid, adjNumbers);
    int max3 = max_minorDiag(myGrid, adjNumbers);

    if (max1>max2 && max1>max3)
        cout<<max1<<endl;
    else if (max2>max1 && max2>max3)
        cout<<max2<<endl;
    else
        cout<<max3<<endl;

    return 0;
}

/** A foatloban levo elemek legnagyobb szorzatat keresi meg */
int max_mainDiag(mtx myGrid, int adjNumbers)
{
   int maxProduct = 1;
    for (int i=0; i<myGrid.size()-adjNumbers; ++i)
    {
        for (int j=0; j<myGrid.size()-adjNumbers; ++j)
        {
            int product = 1;
            for (int k=0; k<adjNumbers; ++k)
            {
                product*=myGrid[i+k][j+k];
            }
            if (product > maxProduct)
            {
                maxProduct = product;
                cout<<i<<":"<<j<<"-tol foatlosan : "<<maxProduct<<endl;
            }
        }
    }
    return maxProduct;
}

/** A mellekatloban levo elemek legnagyobb szorzatat keresi meg */
int max_minorDiag(mtx myGrid, int adjNumbers)
{
   int maxProduct = 1;
    for (int i=adjNumbers-1; i<myGrid.size(); ++i)
    {
        for (int j=0; j<myGrid.size()-adjNumbers; ++j)
        {
            int product = 1;
            for (int k=0; k<adjNumbers; ++k)
            {
                product*=myGrid[i-k][j+k];
            }
            if (product > maxProduct)
            {
                maxProduct = product;
                cout<<i<<":"<<j<<"-tol mellekatlosan : "<<maxProduct<<endl;
            }
        }
    }
    return maxProduct;
}

/** Megkeresi fuggolegesen es vizszintesen a legnagyobb n szomszed szorzatat */
int max_HV(mtx myGrid, int adjNumbers)
{
    int maxProduct = 1;
    for (int i=0; i<myGrid.size(); ++i)
    {
        for (int j=0; j<myGrid.size()-adjNumbers; ++j)
        {
            int product1 = 1, product2 = 1;
            for (int k=0; k<adjNumbers; ++k)
            {
                product1*=myGrid[i][j+k];
                product2*=myGrid[j+k][i];
            }

            if (product1 > maxProduct)
            {
                maxProduct = product1;
                cout<<i<<":"<<j<<"-tol vizszintesen : "<<maxProduct<<endl;
            }
            if (product2 > maxProduct)
            {
                  maxProduct = product2;
                 cout<<j<<":"<<i<<"-tol fuggolegesen: "<<maxProduct<<endl;
            }
        }
    }
    return maxProduct;
}

/** Beolvas egy matrixot a megadott nevu filebol */
mtx read_matrix(const char * filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    	return mtx();
    	
    mtx mtx_back; //visszateresi matrix
    int N, M;
    fin>>N;
    mtx_back.resize(N);
    fin>>M;
    for (int i=0; i<N; ++i)
    {
        mtx_back[i].resize(M);
        for (int j=0; j<M; ++j)
        {
            fin>>mtx_back[i][j];
        }
    }
    fin.close();
    return mtx_back;
}

/** Matrix kiiratas */
void print_matrix(const mtx & M)
{
    for (int i=0; i<M.size(); ++i)
    {
        for (int j=0; j<M.size(); ++j)
            cout<<setw(2)<<M[i][j]<<" ";
        cout<<endl;
    }
}
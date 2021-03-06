#include "mex.h"
#include "DasControl.h"


void mexFunction(
				 int nlhs, mxArray *plhs[],
				 int nrhs, const mxArray *prhs[])
{
   double* Tm;
   Transform TF;
   
    /* Check for proper number of arguments */
    if (nrhs != 1) {
        mexErrMsgTxt("One input argument required; transform");
        return;
    }
    Tm = mxGetPr(prhs[0]);  
    for(int i=0; i<3; i++)
       for(int j=0; j<3; j++){
           TF.Mtrans[i][j]= Tm[i*3 +j];
    }
    
    Set_Transform(TF);
}
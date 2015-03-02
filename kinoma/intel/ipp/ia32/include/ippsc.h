/* /////////////////////////////////////////////////////////////////////////////
//
//                  INTEL CORPORATION PROPRIETARY INFORMATION
//     This software is supplied under the terms of a license agreement or
//     nondisclosure agreement with Intel Corporation and may not be copied
//     or disclosed except in accordance with the terms of that agreement.
//           Copyright (c) 2001-2006 Intel Corporation. All Rights Reserved.
//
//               Intel(R) Integrated Performance Primitives
//                             Speech Coding
//
*/

#if !defined( __IPPSC_H__ ) || defined( _OWN_BLDPCS )
#define __IPPSC_H__

#if defined (_WIN32_WCE) && defined (_M_IX86) && defined (__stdcall)
  #define _IPP_STDCALL_CDECL
  #undef __stdcall
#endif

#ifndef __IPPDEFS_H__
  #include "ippdefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if !defined( _OWN_BLDPCS )
typedef enum {
    IPP_SPCHBR_4750 = 0,  /* 4.75 kbps */
    IPP_SPCHBR_5150,      /* 5.15 kbps */
    IPP_SPCHBR_5300,      /* 5.3 kbps */
    IPP_SPCHBR_5900,      /* 5.9 kbps */
    IPP_SPCHBR_6300,      /* 6.3 kbps */
    IPP_SPCHBR_6600,      /* 6.60 kbps */
    IPP_SPCHBR_6700,      /* 6.7 kbps */
    IPP_SPCHBR_7400,      /* 7.4 kbps */
    IPP_SPCHBR_7950,      /* 7.95 kbps */
    IPP_SPCHBR_8850,      /* 8.85 kbps */
    IPP_SPCHBR_9600,      /* 9.60 kbps */
    IPP_SPCHBR_10200,     /* 10.2 kbps */
    IPP_SPCHBR_12200,     /* 12.2 kbps */
    IPP_SPCHBR_12650,     /* 12.65 kbps */
    IPP_SPCHBR_12800,     /* 12.8 kbps */
    IPP_SPCHBR_14250,     /* 14.25 kbps */
    IPP_SPCHBR_15850,     /* 15.85 kbps */
    IPP_SPCHBR_16000,     /* 16 kbps */
    IPP_SPCHBR_18250,     /* 18.25 kbps */
    IPP_SPCHBR_19850,     /* 19.85 kbps */
    IPP_SPCHBR_23050,     /* 23.05 kbps */
    IPP_SPCHBR_23850,     /* 23.85 kbps */
    IPP_SPCHBR_24000,     /* 24 kbps */
    IPP_SPCHBR_32000,     /* 32 kbps */
    IPP_SPCHBR_40000,     /* 40 kbps */
    IPP_SPCHBR_DTX        /* Discontinuous TX mode */
} IppSpchBitRate;

typedef enum {
    IPP_PCM_MULAW = 0,   /* mu-Law */
    IPP_PCM_ALAW,        /* A-Law */
    IPP_PCM_LINEAR       /* uniform PCM */
} IppPCMLaw;

typedef enum {
    IPP_PCM_FREQ_8000 = 8000,                /* 8  kHz  */
    IPP_PCM_FREQ_16000 = 16000               /* 16 kHz */
} IppPCMFrequency;

typedef struct {
      Ipp16s      pPrevSignalSublevel[9];   /* signal sublevel vector */
      Ipp16s      pPrevSignalLevel[9];      /* previous signal level vector */
      Ipp16s      pPrevAverageLevel[9];     /* average signal level */
      Ipp16s      pBkgNoiseEstimate[9];     /* background noise estimate vector */
      Ipp16s      pFifthFltState[6];        /* 5th order filters history */
      Ipp16s       pThirdFltState[5];       /* 3rd order filters history */
      Ipp16s      burstCount;               /* burst counter */
      Ipp16s      hangCount;                /* hangover counter */
      Ipp16s      statCount;                /* stationarity counter */
      Ipp16s      vadReg;                   /* intermediate vad decision */
      Ipp16s      complexHigh;              /* high for complex signal decision */
      Ipp16s      complexLow;               /* low for ccomplex signal decision */
      Ipp16s      complexHangTimer;         /* complex hangover timer */
      Ipp16s      complexHangCount;         /* complex hangover counter */
      Ipp16s      complexWarning;           /* complex_warining flag */
      Ipp16s      corrHp;                   /* High-pass filtered signal correlation */
      Ipp16s      pitchFlag;                /* pitch flag by pitch detection */
} IppGSMAMRVad1State;

typedef struct {
      Ipp32s      pEngyEstimate[16];        /* channel energy estimate vector of */
                                            /* current half-frame */
      Ipp32s      pNoiseEstimate[16];       /* channel noise estimiate vector of */
                                            /* current half-frame */
      Ipp16s      pLongTermEngyDb[16];      /* channel long-term log energy vector */
                                            /* of current half-frame */
      Ipp16s      preEmphasisFactor;        /* pre-emphasize factor */
      Ipp16s      updateCount;              /* update counter */
      Ipp16s      lastUpdateCount;          /* last update counter */
      Ipp16s      hysterCount;              /* hyster counter */
      Ipp16s      prevNormShift;            /* previous normalize shift bits */
      Ipp16s      shiftState;               /* previous half-frame shift state */
      Ipp16s      forcedUpdateFlag;         /* forced update flag */
      Ipp16s      ltpSnr;                   /* long-term peak SNR */
      Ipp16s      variabFactor;             /* background noise variablity factor */
      Ipp16s      negSnrBias;               /* negative SNR sensitivity Bias */
      Ipp16s      burstCount;               /* burst counter */
      Ipp16s      hangOverCount;            /* hangover counter */
      Ipp32s      frameCount;               /* frame counter */
} IppGSMAMRVad2State;

typedef    struct Ipp32s_EC_Sfs_Def    {
    Ipp32s    val;
    Ipp32s    sf;
} Ipp32s_EC_Sfs;

#endif /* _OWN_BLDPCS */

/* /////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                   Functions declarations
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippscGetLibVersion
//  Purpose:     getting of the library version
//  Returns:     the structure of information about version
//               of ippSC library
//  Parameters:
//
//  Notes:       not necessary to release the returned structure
*/
IPPAPI( const IppLibraryVersion*, ippscGetLibVersion, (void) )


/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsHighPassFilterSize
//  Purpose:     Knowing of G729 high pass preprocessing filter size demand
//  Parameters:
//    pSize      Pointer to the output value of the memory size needed for filtering
//  Returns:
//    ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsHighPassFilterSize_G729, (int *pSize) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsHighPassFilterInit
//  Purpose:     Initialization of the memory allocated for preprocessing filter
//  Parameters:
//    pMem    pointer to the memory supplied for filtering
//  Returns:  ippStsNoErr, if no errors
//
*/
IPPAPI( IppStatus, ippsHighPassFilterInit_G729, (const Ipp16s *pCoeff, char* pMem) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsHighPassFilter
//  Purpose:     G729 input signal preprocessing, consists of two functions applied:
//                  - scaling ( devide by a factor 2)
//                  - high-pass filtering
//  Parameters:
//    pSrcDst        pointer to the vector for inplace operation
//    pMem    pointer to the memory supplied for filtering
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsHighPassFilter_G729_16s_ISfs, (Ipp16s* pSrcDst, int len, int scaleFactor,
        char* pMem) )
IPPAPI( IppStatus, ippsHighPassFilter_G723_16s, (const Ipp16s* pSrc, Ipp16s* pDst, int* pMem) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsMul
//  Purpose:     multiply operations upon every element of
//               the source vectors.
//               rounding to nearest:
//                  const1 = 1<<(scaleFactor-1)
//                  (a*b+const1)>>scaleFactor;
//  Parameters:
//    pSrc            pointer to the input vector
//    pSrc1           pointer to the first source vector
//    pSrc2           pointer to the second source vector
//    pDst            pointer to the output vector
//    pSrcDst         pointer to the source/destination vector
//    len             length of the vectors
//    scaleFactor     scale factor value
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsMul_NR_16s_Sfs, (const Ipp16s*  pSrc1, const Ipp16s*  pSrc2,
       Ipp16s*  pDst, int len, int scaleFactor) )
IPPAPI( IppStatus, ippsMul_NR_16s_ISfs, (const Ipp16s*  pSrc, Ipp16s*  pSrcDst,
       int len, int scaleFactor) )
IPPAPI( IppStatus, ippsMulC_NR_16s_ISfs, (Ipp16s  val, Ipp16s*  pSrcDst, int len, int scaleFactor) )
IPPAPI( IppStatus, ippsMulC_NR_16s_Sfs, ( const Ipp16s* pSrc, Ipp16s val, Ipp16s* pDst,
       int len, int scaleFactor) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsMulPowerC
//  Purpose:     power weighting of every element of the source vectors
//               dst[i] = pow(val, i)*src[i] ; i=0..len-1
//               with rounding to nearest:
//                  const1 = 1<<(scaleFactor-1)
//                  (a*b+const1)>>scaleFactor;
//  Parameters:
//    pSrc            pointer to the input vector
//    pDst            pointer to the output vector
//    len             length of the vectors
//    scaleFactor     scale factor value
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsMulPowerC_NR_16s_Sfs, (const Ipp16s*  pSrc, Ipp16s  val, Ipp16s*  pDst,
       int len, int scaleFactor) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsInvSqrt
//  Purpose:     Inverted square root with normalization
//  Parameters:
//    pSrcDst    pointer to the input/output vector
//    len        length of the input vector
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsInvSqrt_32s_I, (Ipp32s *pSrcDst, int len ) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsAutoScale
//  Purpose:     Autoscaling:  Find and normalize (shift left) the absolute
//               maximal element and then do the same shift for all other elements
//  Parameters:
//    pSrc       pointer to the input vector
//    pDst       pointer to the output vector
//    pSrcDst    pointer to the input/output vector
//    len        length of the input vector
//    pScale     pointer to the output scaling factor
//               (number of bit the output vector has been shifted left)
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsAutoScale_16s, (const Ipp16s *pSrc,  Ipp16s *pDst, int Len , int *pScale) )
IPPAPI( IppStatus, ippsAutoScale_16s_I, ( Ipp16s *pSrcDst, int Len , int *pScale) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsAutoCorrLagMax
//  Purpose:     Find the maximum of the correlation for the given lag range
//                 r[lag]=SUM(n=0,...,len-1) src[n]*src[n-lag]  - backward
//                 r[lag]=SUM(n=0,...,len-1) src[n]*src[n+lag]  - forward
//                 within the range [lowerLag,upperLag] of the lags.
//  Parameters:
//    pSrc       pointer to the input vector
//    len        length of the input vector
//    lowerLag   lower input lag value
//    upperLag   upper input lag value
//    pMax       pointer to the output maximum of the correlation
//    maxLag     pointer to the output lag value that hold maximum
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsAutoCorrLagMax_Fwd_16s, (const Ipp16s *pSrc, int len, int lowerLag,
       int upperLag, Ipp32s *pMax, int *maxLag ) )
IPPAPI( IppStatus, ippsAutoCorrLagMax_Inv_16s, (const Ipp16s *pSrc, int len, int lowerLag,
       int upperLag, Ipp32s *pMax, int *maxLag ) )
IPPAPI( IppStatus, ippsAutoCorrLagMax_32f,(const Ipp32f *pSrc, int len, int lowerLag,
       int upperLag, Ipp32f *pMax, int *maxLag ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsAutoCorr_NormE
//  Purpose:     Compute autocorrelation using formula:
//                 r[n]=SUM(i=0,...,len-n-1) src[i]*src[i+n], n=0,...,lenDst-1
//               Norm in function name means multiplication of result by normalzation factor
//               of corr[0].
//  Parameters:
//    pSrc       pointer to the input vector
//    len        length of the input vector
//    step
//    pDst       pointer to the output autocorrelation vector
//    lenDst     length of the output vector
//  Returns:  ippStsNoErr, if no errors
//            ippStsOverflow, if at least one result really was saturated
*/
IPPAPI( IppStatus, ippsAutoCorr_16s32s,
       (const Ipp16s *pSrc, int srcLen, Ipp32s *pDst, int dstLen ))
IPPAPI( IppStatus, ippsAutoCorr_NormE_16s32s, (const Ipp16s *pSrc, int len, Ipp32s *pDst,
       int lenDst, int *pNorm) )
IPPAPI( IppStatus, ippsAutoCorr_NormE_NR_16s, (const Ipp16s *pSrc, int len, Ipp16s *pDst,
       int lenDst, int *pNorm) )
IPPAPI( IppStatus, ippsAutoCorr_NormE_G723_16s, (const Ipp16s *pSrc, Ipp16s *pDst, int *pNorm) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsToeplizMatrix
//  Purpose:     Compute of the autocorrelation matrix for the impulse response
//  Parameters:
//    pSrc       pointer to the input vector (Impulse response)
//    pDst       pointer to the output autocorrelation matrix
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsToeplizMatrix_G729_16s32s,(const Ipp16s *pSrcImpulseResponse, Ipp32s *pDstMatrix))
IPPAPI( IppStatus, ippsToeplizMatrix_G729_16s,   (const Ipp16s *pSrcImpulseResponse, Ipp16s *pDstMatrix))
IPPAPI( IppStatus, ippsToeplizMatrix_G723_16s32s,(const Ipp16s *pSrcImpulseResponse, Ipp32s *pDstMatrix))
IPPAPI( IppStatus, ippsToeplizMatrix_G723_16s,   (const Ipp16s *pSrcImpulseResponse, Ipp16s *pDstMatrix))
IPPAPI( IppStatus, ippsToeplizMatrix_G729_32f,   (const Ipp32f *pSrcImpulseResponse, Ipp32f *pDstMatrix))
IPPAPI( IppStatus, ippsToeplizMatrix_G729D_32f,  (const Ipp32f *pSrcImpulseResponse, Ipp32f *pDstMatrix))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsCrossCorr
//  Purpose:     Compute crosscorrelation of two vectors using formula:
//                 r[k]=SUM(i=k,...,len) src2[i]*src1[j-i] k=0,...,lenDst-1
//               result is scaled so that the crosscorrelation maximum is int 13 bit
//  Parameters:
//    pSrc1      pointer to the input vector
//    pSrc2      pointer to the input vector
//    len        length of the correlation
//    pDst       pointer to the output crosscorrelation vector
//    lenDst     length of the output vector
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsCrossCorr_NormM_16s, (const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len,
       Ipp16s *pDst) )
IPPAPI( IppStatus, ippsCrossCorr_16s32s_Sfs, (const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len,
       Ipp32s *pDst, int scaleFactor) )
IPPAPI(IppStatus, ippsCrossCorr_NR_16s, ( const Ipp16s* pSrc1, const Ipp16s* pSrc2, int len,
       Ipp16s* pDst, int lenDst))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsCrossCorrLagMax
//  Purpose:     Find the maximum of the cross-correlation for the given lag range [0,lag]
//                 r[lag]=SUM(n=0,...,len-1) src1[n]*src2[n+lag]
//                 within the range [lowerLag,upperLag] of the lags.
//  Parameters:
//    pSrc       pointer to the input vector
//    len        length of the input vector
//    lag        max lag value
//    pMax       pointer to the output maximum of the correlation
//    pMaxLag    pointer to the output lag value that hold maximum
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsCrossCorrLagMax_16s,   (const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len,
                                              int lag, Ipp32s *pMax, int *pMaxLag))
IPPAPI(IppStatus, ippsCrossCorrLagMax_32f64f,(const Ipp32f *pSrc1, const Ipp32f *pSrc2, int len,
                                              int lag, Ipp64f *pMax, int *pMaxLag ))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsOpenLoopPitchSearch
//  Purpose:     Find the best codebook delay by open-loop pitch analysis
//                 r[lag]=SUM(n=0,...,L_FRAME-1) src[n]*src[n-lag]
//                 within the range [lowerLag,upperLag] of the lags.
//  Parameters:
//    pSrc       pointer to the input vector of range [pSrc-upperLag,pSrc+L_FRAME-1]
//    bestLag    pointer to the output best open-loop pitch lag
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsOpenLoopPitchSearch_G729_16s, (const Ipp16s *pSrc, Ipp16s* bestLag) )
IPPAPI( IppStatus, ippsOpenLoopPitchSearch_G729A_16s,(const Ipp16s *pSrc, Ipp16s* bestLag) )
IPPAPI( IppStatus, ippsOpenLoopPitchSearch_G729A_32f,(const Ipp32f *pSrc, Ipp32s* bestLag))
IPPAPI( IppStatus, ippsOpenLoopPitchSearch_G723_16s, (const Ipp16s *pSrc, Ipp16s* bestLag ) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsDotProd
//  Purpose:     Compute dot product of two input signals using formula:
//                 energy=SUM(n=0,...,len-1) src1[n]*src2[n]
//               AutoScale function interchange downscaling by 1 of input vectors until
//               no overflow occured, returns total number of shifts right.
//  Parameters:
//    pSrc1    pointer to the first input vector
//    pSrc2    pointer to the second input vector
//    len      length of each input vectors
//    pDp      pointer to the output result value
//    pSfs     pointer to the output total number of shifts right done to avoid overflow
//  Returns:  ippStsNoErr, if no errors
//            ippStsOverflow, if at least one result really was saturated
*/
IPPAPI( IppStatus, ippsDotProd_G729A_16s32s,
   (const Ipp16s* pSrc1, const Ipp16s* pSrc2, int len, Ipp32s* pDp) )
IPPAPI( IppStatus, ippsDotProd_G729A_32f,
   (const Ipp32f* pSrc1, const Ipp32f* pSrc2, int len, Ipp32f* pDp) )
IPPAPI( IppStatus, ippsDotProdAutoScale_16s32s_Sfs,
   (const Ipp16s* pSrc1, const Ipp16s* pSrc2, int len, Ipp32s* pDp, int *pSfs) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLagWindow
//  Purpose:     A 60 Hz bandwidth expansion is applied to input auto-correlation
//                 r[0]=1.0001*r[0];
//                 r[k]=wlag[k]*r[k];
//               60 Hz bandwidth expansion coefficients
//               w_lag(k)=exp[-1/2*(2*pi*f0*k/fs)^2]
//               where : f0 = 60   Hz
//                     fs = 8000 Hz
//  Parameters:
//    pSrcDst    pointer to the autocorrelation vector
//    len        length of the autocorrelation vector
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsLagWindow_G729_32s_I, (Ipp32s *pSrcDst, int len) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLSPToLSF
//               pLSF[i] = arccos(pLSP[i]);  i=0,...,10
//    pLSP       pointer to the LSP input vector of values 15 bit scaled in range [-1:1]
//    pLSF       pointer to the LSF output vector
//               ippsLSPToLSF_G729_16s:      13 bit scaled in range [0:pi]
//               ippsLSPToLSF_Norm_G729_16s: 15 bit scaled in range [0:0.5]
//  Parameters:
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsLSPToLSF_G729_16s, (const Ipp16s *pLSP, Ipp16s *pLSF) )
IPPAPI( IppStatus, ippsLSPToLSF_Norm_G729_16s, (const Ipp16s *pLSP, Ipp16s *pLSF) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLSFQuant
//  Purpose:     Quantize of LSPs
//  Parameters:
//    pLSF             pointer to the input vector of LSF representation of LSP
//    pQuantLSFTable   pointer to the table of the previously quantized LSFs
//    prevLSF          pointer to the input vector of previously quantized LSFs
//    pQuantLSF        pointer to the output vector of quantized LSF
//    quantIndex       pointer to the output combined codebook indices
//                     G729 - MA,L0,L1,L2
//  Returns:  ippStsNoErr, if no errors
//            ippStsLSFHigh, ippStsLSFLow or ippStsLSFLowAndHigh warnings
*/
IPPAPI( IppStatus, ippsLSFQuant_G729_16s, (const Ipp16s *pLSF, Ipp16s *pQuantLSFTable,
        Ipp16s *pQuantLSF, Ipp16s *quantIndex) )
IPPAPI( IppStatus, ippsLSFQuant_G729B_16s, (const Ipp16s *pLSF, Ipp16s *pQuantLSFTable,
        Ipp16s *pQuantLSF, Ipp16s *quantIndex) )
IPPAPI ( IppStatus, ippsLSFQuant_G729B_32f,(const Ipp32f *pLSF, Ipp32f *pQuantLSFTable,
        Ipp32f *pQuantLSF, int  *quantIndex) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLSFDecode
//  Purpose:     Construct LSFs by codebook indices
//  Parameters:
//    quantIndex       pointer to the input vector of codebook indices ( L0,L1,L2 )
//    pQuantLSFTable   pointer to the table of previously quantized LSFs
//    pPrevLSF         pointer to the input vector of the previously quantized LSFs
//    pLSF             pointer to the constructed LSF output vector
//  Returns:  ippStsNoErr, if no errors
//            ippStsLSFHigh, ippStsLSFLow or ippStsLSFLowAndHigh warnings
*/
IPPAPI( IppStatus, ippsLSFDecode_G729_16s, (const Ipp16s *quantIndex, Ipp16s *pQuantLSPTable,
       Ipp16s *pQuantLSF) )
IPPAPI (IppStatus, ippsLSFDecode_G729_32f, (const int *quantIndex, Ipp32f *pQuantLSFTable,
       Ipp32f *pQuantLSF) )
IPPAPI( IppStatus, ippsLSFDecodeErased_G729_16s, (Ipp16s maIndex, Ipp16s *pQuantLSFTable,
       const Ipp16s *pLSF) )
IPPAPI ( IppStatus,ippsLSFDecodeErased_G729_32f, (int maIndex, Ipp32f *pQuantLSFTable,
       const Ipp32f *pSrcPrevLSF))
IPPAPI( IppStatus, ippsLSFDecode_G729B_16s, (const Ipp16s *quantIndex, Ipp16s *pQuantLSFTable,
        Ipp16s *pLSF) )
IPPAPI ( IppStatus, ippsLSFDecode_G729B_32f,(const int *quantIndex, Ipp32f *pQuantLSFTable, Ipp32f *pDstQLsp ))
IPPAPI( IppStatus, ippsLSFDecode_G723_16s, ( const Ipp16s *quantIndex, const Ipp16s *pPrevLSF,
        int erase, Ipp16s *pLSF ) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLSFToLSP
//  Purpose:     LSF interpolation and conversion to LPC
//  Parameters:
//    pLSF       pointer to the LSF input vector
//    pLPC       pointer to the LPC output vector of values in range [-1,1] 15 bit scaled
//  Returns:  ippStsNoErr, if no errors
//
*/
IPPAPI( IppStatus, ippsLSFToLSP_G729_16s, (const Ipp16s *pLSF, Ipp16s *pLSP) )
IPPAPI( IppStatus, ippsLSFToLSP_GSMAMR_16s, (const Ipp16s *pLSF, Ipp16s *pLSP) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsInterpolation
//  Purpose:     interpolation of two vector
//               ippsInterpolation_G729_16s: dst = ((src1+sign(src1) )>>1+((src2+sign(src2) )>>1
//               ippsInterpolationC_G729_16s_Sfs: dst = (val1*src1+val2*src2)>>scaleFactor
//               ippsInterpolation_GSMAMR_16s: dst = (src1>>2)+(src2-(src2>>2))
//  Parameters:
//    pSrc1      pointer to the input vector1
//    pSrc2      pointer to the input vector2
//    pDst       pointer to the interpolated output vector
//    val1       interp. coeff. of first vector
//    val2       interp. coeff. of second vector
//    scaleFactor scaling factor to apply to the result
//    len        length of the vectors
/  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsInterpolate_G729_16s, (const Ipp16s *pSrc1, const Ipp16s *pSrc2,
        Ipp16s *pDst, int  len) )
IPPAPI( IppStatus, ippsInterpolateC_G729_16s_Sfs, (const Ipp16s *pSrc1, Ipp16s val1,
        const Ipp16s *pSrc2, Ipp16s val2, Ipp16s *pDst, int  len, int scaleFactor) )
IPPAPI( IppStatus, ippsInterpolateC_NR_G729_16s_Sfs, (const Ipp16s *pSrc1, Ipp16s val1,
        const Ipp16s *pSrc2, Ipp16s val2, Ipp16s *pDst, int  len, int scaleFactor) )
IPPAPI( IppStatus, ippsInterpolateC_G729_32f,(const Ipp32f *pSrc1, Ipp32f val1,
       const Ipp32f *pSrc2, Ipp32f val2, Ipp32f *pDst, int len))
IPPAPI ( IppStatus, ippsInterpolate_GSMAMR_16s,
        (const Ipp16s *pSrc1, const Ipp16s *pSrc2, Ipp16s *pDst, int  len))
/* ////////////////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLSPToLPC
//  Purpose:     LSP conversion to LPC
//  Parameters:
//    pLSP       pointer to the LSP input vector
//    pLPC       pointer to the LPC output vector of values in range [-1,1] 15 bit scaled
//    pLSFLPC    pointer to the input LSF/output LPC vector
//  Returns:  ippStsNoErr, if no errors
//
*/
IPPAPI( IppStatus, ippsLSPToLPC_G729_16s, (const Ipp16s *pSrcLSP, Ipp16s *pDstLPC) )
IPPAPI( IppStatus, ippsLSPToLPC_G729_32f, (const Ipp32f *pSrcLSP, Ipp32f *pDstLPC) )
/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:        ippsResidualFilter
//  Purpose:     Compute the LPC residual by filtering the input speech through A(z)
//  Parameters:
//    pSrc       pointer to the input vector[-10,..,-1,0,...,39]
//    pSrcSpeech pointer to the input vector[-valLPCOrder,..,-1,0,...,,len-1]
//    pLPC       pointer to the input LPC
//    pDst       pointer to the output vector[40]
//    pDstResidualSignal - pointer to the output vector of length[len]
//    len        length of output vector
//  Returns:  ippStsNoErr, if no errors
//
*/
IPPAPI( IppStatus, ippsResidualFilter_G729_16s, ( const Ipp16s * pSrc, const Ipp16s * pLPC,
        Ipp16s * pDst) )
IPPAPI( IppStatus, ippsResidualFilter_G729E_16s,(
  const Ipp16s *pSrcLpc, Ipp16s valLPCOrder, const Ipp16s *pSrcSpeech, Ipp16s *pDstResidualSignal, int len))
/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:        ippsSynthesisFilter
//  Purpose:     Compute the sheech signal by synthesis filtering of the input speech through
//                   1/A(z)
//  Parameters:
//    pSrc,pSrcSignal pointer to the input vector[len]
//    pLPC           pointer to the input LPC[0,..,10]
//    pSrcLpc        pointer to the input LPC[0,..,order]
//    pSrcDst        pointer to the history input/filtered output
//    pDst,pSrcDstSignal pointer to the filtered output vector[len]
//    pMem           Pointer to the memory[-10,...,-1]  supplied for filtering
//    pSrcDstSynFltMemory Pointer to the memory[-order,..,-1] supplied for filtering
//  Returns:  ippStsNoErr, if no errors
//            ippStsOverflow, if at least one result really was saturated
*/
IPPAPI( IppStatus, ippsSynthesisFilter_NR_16s_Sfs, (const Ipp16s * pLPC, const Ipp16s * pSrc,
        Ipp16s * pDst, int len, int scaleFactor, const Ipp16s *pMem) )
IPPAPI( IppStatus, ippsSynthesisFilterLow_NR_16s_ISfs, (const Ipp16s * pLPC, Ipp16s * pSrcDst,
       int len, int scaleFactor, const Ipp16s *pMem) )
IPPAPI( IppStatus, ippsSynthesisFilter_NR_16s_ISfs, (const Ipp16s * pLPC, Ipp16s * pSrcDst,
       int len, int scaleFactor, const Ipp16s *pMem) )
IPPAPI( IppStatus, ippsSynthesisFilter_G729_16s,
       (const Ipp16s * pSrcResidual, const Ipp16s * pSrcLPC, Ipp16s * pSrcDstSpch))
IPPAPI(IppStatus, ippsSynthesisFilterZeroStateResponse_NR_16s,
       (const Ipp16s * pSrcLPC, Ipp16s * pDstImp, int len, int scaleFactor))
IPPAPI( IppStatus, ippsSynthesisFilter_G729E_16s,(
   const Ipp16s *pSrcLpc, Ipp16s order, const Ipp16s *pSrcSignal,
   Ipp16s *pDstFltSignal, int len, Ipp16s *pSrcDstSynFltMemory))
IPPAPI( IppStatus, ippsSynthesisFilter_G729_32f,(
   const Ipp32f *pSrcLpc, Ipp32s order, const Ipp32f *pSrcSignal,
   Ipp32f *pDstFltSignal, int len, Ipp32f *pSrcDstSynFltMemory))
IPPAPI( IppStatus, ippsSynthesisFilter_G729E_16s_I,(
   const Ipp16s *pSrcLpc, Ipp16s order, Ipp16s *pSrcDstSignal,
   int len, Ipp16s *pSrcDstSynFltMemory))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsConv
//  Purpose:    Linear Convolution of 1D signals
//               dst[n] = sum(i=[0,n])(src1[i]*src2[n-i]), n=[0,len-1]
//              computation is the same as for
//                  ippsConv_16s32s(pSrc1,len,pSrc2,len,pDst)
//              but only len results are computed and written to destination vector.
//  Parameters:
//    pSrc1     pointer to the first source vector
//    pSrc2     pointer to the second source vector
//    pDst      pointer to the destination vector
//    len       length of the destination vector
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsConvPartial_16s_Sfs,
       ( const Ipp16s* pSrc1, const Ipp16s* pSrc2,  Ipp16s* pDst, int len, int scaleFactor) )
IPPAPI(IppStatus, ippsConvPartial_16s32s,
       ( const Ipp16s* pSrc1, const Ipp16s* pSrc2,  Ipp32s* pDst, int len))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsDecodeAdaptiveVector
//  Purpose:    Compute adaptive-codebook vector by interpolatindg the past excitation signal
//              at the given integer delay and fraction
//  Parameters:
//    pSrcDstPrevExcitation   pointer to the source/destination past excitation signal
//    pDstAdptVector   pointer to the destination adaptive-codebook vector
//    pSrcDelay        pointer to fractional pitch delay:
//                        pSrcDelay[0] -  pitch delay
//                        pSrcDelay[1] -  pitch fraction
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsDecodeAdaptiveVector_G729_16s_I,(const Ipp16s * pSrcDelay,
       Ipp16s * pSrcDstPrevExcitation))
IPPAPI( IppStatus, ippsDecodeAdaptiveVector_G729_32f_I,(const Ipp32s * pSrcDelay,
       Ipp32f * pSrcDstPrevExcitation))
IPPAPI( IppStatus, ippsDecodeAdaptiveVector_G729_16s,(const Ipp16s * pSrcDelay,
       Ipp16s * pSrcDstPrevExcitation, Ipp16s * pDstAdptVector))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsAdaptiveCodebookContribution
//  Purpose:    Update target vector for codebook search
//              by subtracting the adaptive codebook contribition:
//                pDstFltAdptVector[i] = pSrcAdptTarget[i]-gain*pDstFltAdptVector[i];
//              G.729 3.8.1
//  Parameters:
//    gain               adaptive codebook gain
//    pFltAdptVector     pointer to the filtered adaptive codebook vector y(n)
//    pSrcAdptTarget     pointer to the target signal
//    pDstAdptTarget     pointer to the output target signal
                         (updated by subtracting the adaptive codebook contribition)
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus,ippsAdaptiveCodebookContribution_G729_16s, (Ipp16s gain,
       const Ipp16s *pFltAdptVector, const Ipp16s *pSrcAdptTarget, Ipp16s* pDstAdptTarget))
IPPAPI(IppStatus, ippsAdaptiveCodebookContribution_G729_32f,(Ipp32f gain,
       const Ipp32f *pFltAdptVector, const Ipp32f *pSrcAdptTarget, Ipp32f* pDstAdptTarget))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsFixedCodebookSearch
//  Purpose:    Search in fixed codebook for four non zero pulses, which minimize MSE
//              between the weighted input speech and weighted teconstructed speech.
//              The target signal used in the close-loop pitch search is updated by
//              substracting of adaptive-codebook contribution by formulae:
//                 x[n] = x[n] - g*y[n], n=0,...,39
//              where:      g - adaptive-codebook gain
//                          y - filtered adaptive-codebook vector
//                          x - weighted input
//  Parameters:
//    pSrcFixedCorr   pointer to the correlation vector of the impulse response and target
//    pSrcDstMatrix   pointer to the correlation matrix of impulse response.
//    pDstFixedVector pointer to the output selected acodeword
//    pSearchTimes    pointer to the input/output extra searching time
//    pDstFixedIndex  pointer to the output codeword index
//    pSrc1     pointer to the correlation vector of the impulse response and target
//    pSrcDst   pointer to the correlation matrix of impulse response.
//    pSrc2     Impulse response
//    pDst1     pointer to the output selected acodeword
//    pDst2     pointer to the output filteredcodeword
//    pSign     pointer to the output sign of 4 pulses selected
//    subFrame  input sub frame number      (0,1)
//    extraTime pointer to the input/output extra searching time
//    pDstFixedIndex     pointer to the output codeword index
//    valLpMode       Backward / Forward LP mode indication
//    len       length of the destination vectors
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsFixedCodebookSearch_G729_32s16s, (const Ipp16s *pSrcFixedCorr,
       Ipp32s *pSrcDstMatrix, Ipp16s *pDstFixedVector,
       Ipp16s *pDstFixedIndex, Ipp16s *pSearchTimes, Ipp16s subFrame))
IPPAPI(IppStatus, ippsFixedCodebookSearch_G729_16s, (const Ipp16s *pSrcFixedCorr,
       Ipp16s *pSrcDstMatrix, Ipp16s *pDstFixedVector,
       Ipp16s *pDstFixedIndex, Ipp16s *pSearchTimes, Ipp16s subFrame))
IPPAPI(IppStatus,ippsFixedCodebookSearch_G729A_32s16s,(const Ipp16s *pSrcFixedCorr,
       Ipp32s *pSrcDstMatrix, Ipp16s *pDstFixedVector, Ipp16s *pDstFixedIndex))
IPPAPI(IppStatus,ippsFixedCodebookSearch_G729A_16s,(const Ipp16s *pSrcFixedCorr,
       Ipp16s *pSrcDstMatrix, Ipp16s *pDstFixedVector, Ipp16s *pDstFixedIndex))
IPPAPI(IppStatus, ippsFixedCodebookSearch_G729E_16s,(
       Ipp16s valLpMode, const Ipp16s* pSrcFixedTarget, const Ipp16s* pSrcLtpResidual,
       const Ipp16s* pSrcImpulseResponse, Ipp16s* pDstFixedVector, Ipp16s* pDstFltFixedVector,
       Ipp16s* pDstFixedIndex))
IPPAPI(IppStatus, ippsFixedCodebookSearch_G729D_16s,(const Ipp16s *pSrcFixedCorr,
       const Ipp16s *pSrcImpulseResponse, Ipp16s *pDstFixedVector, Ipp16s *pDstFltFixedVector,
       Ipp16s *pDstSign, Ipp16s *pDstFixedIndex))
IPPAPI(IppStatus, ippsFixedCodebookSearch_G729_32f,(const Ipp32f *pSrcFixedCorr,
       Ipp32f *pSrcDstMatrix, Ipp32f *pDstFixedVector, Ipp32s *pDstFixedIndex,
       Ipp32s *pSearchTimes, Ipp32s subFrame))
IPPAPI(IppStatus,ippsFixedCodebookSearch_G729A_32f,(const Ipp32f *pSrcFixedCorr,
       Ipp32f *pSrcDstMatrix, Ipp32f *pDstFixedVector, Ipp32s *pDstFixedIndex))
IPPAPI(IppStatus,ippsFixedCodebookSearch_G729D_32f,(Ipp32f *pSrcDstFixedCorr,
       Ipp32f *pSrcDstMatrix, const Ipp32f *pSrcImpulseResponse,
       Ipp32f *pDstFixedVector, Ipp32f *pDstFltFixedVector, Ipp32s *pDstFixedIndex))
IPPAPI(IppStatus,ippsFixedCodebookSearch_G729E_32f, (int mode,
       Ipp32f *pSrcDstFixedCorr, const Ipp32f *pSrcLtpResidual,
       const Ipp32f *pSrcImpulseResponse, Ipp32f *pDstFixedVector,
       Ipp32f *pDstFltFixedVector, Ipp32s *pDstFixedIndex))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsHarmonicFilter
//  Purpose:    Enchance harmonic component of signal by formulae:
//              y[n] = x[n] + val * x[n-T] - harmonic nose shaping: 1+val*z^(-T)
//              y[n] = y[n] + val * y[n-T] - adaptive pre-filter:  1/(1-val*z^(-T) )
//  Parameters:
//    val       the input factor of filter
//    T         the value of delay
//    pSrc      pointer to the input vector
//    pDst      pointer to the output vector
//    pSrcDst   pointer to the input/output vector
//    len       number of output results needed.
//                  pSrc[-T,1] or pSrcDst[-T,-1] shell be done
//              pDst[0,len-1] or pSrcDst[0,len-1] will be computed.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsHarmonicFilter_16s_I,(Ipp16s val, int T, Ipp16s *pSrcDst, int len) )
IPPAPI( IppStatus, ippsHarmonicFilter_32f_I,(Ipp32f val, int T, Ipp32f *pSrcDst, int len) )
IPPAPI( IppStatus, ippsHarmonicFilter_NR_16s, (Ipp16s val, int T, const Ipp16s *pSrc,
       Ipp16s *pDst, int len) )

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsGainQuant
//  Purpose:    Quantization of the adaptive codebook gains
//  Parameters:
//    pSrcAdptTarget      pointer to the input target vector x(n).
//    pSrcFltAdptVector   pointer to the input filterd adaptive codebook vector y(n)
//    pSrcFixedVector     pointer to the input pre-filtered codebook contribition c(n)
//    pSrcFltFixedVector  pointer to the input filtered codebook vector z(n)
//    pSrcDstEnergyErr    pointer to the input/output energy error vector
//                        for 4 previous subframes
//    pDstQGain           pointer to the output gains:
//                        gain pitch = pDstQGainIndex[0]
//                        gain code  = pDstQGainIndex[1]
//    pDstQGainIndex      pointer to the output codebook indexes found
//    tameProcess         1 - taming is needed
//
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsGainQuant_G729_16s, (
       const Ipp16s *pSrcAdptTarget, const Ipp16s *pSrcFltAdptVector,
       const Ipp16s * pSrcFixedVector, const Ipp16s *pSrcFltFixedVector,
       Ipp16s *pSrcDstEnergyErr, Ipp16s *pDstQGain, Ipp16s *pDstQGainIndex, Ipp16s tameProcess))
IPPAPI(IppStatus, ippsGainQuant_G729D_16s, (
       const Ipp16s  *pSrcAdptTarget, const Ipp16s  *pSrcFltAdptVector,
       const Ipp16s  *pSrcFixedVector, const Ipp16s  *pSrcFltFixedVector,
       Ipp16s *pSrcDstEnergyErr, Ipp16s *pDstQGain, Ipp16s *pDstQGainIndex, Ipp16s tameProcess))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsGainCodebookSearch_G729
//  Purpose:    Searching procedure used in adaptive codebook gains quantization
//              gain pitch = gcdbk1[pDstIdxs[0]][0] + gcdbk2[pDstIdxs[1]][0]
//              gain code  = gcdbk1[pDstIdxs[0]][1] + gcdbk2[pDstIdxs[1]][1]
//              where gcdbk1 = gbk1_6k,  gcdbk2 = gbk1_6k for D mode
//                    gcdbk1 = gbk1,     gcdbk2 = gbk1 for other then D modes
//  Parameters:
//    pSrcCorr          Pointer to the correlations :
//                         pSrcCorr[0] =    y(n)*y(n)
//                         pSrcCorr[1] = -2.x(n)*y(n)
//                         pSrcCorr[2] =    z(n)*z(n)
//                         pSrcCorr[3] = -2.x(n)*z(n)
//                         pSrcCorr[4] = -2.y(n)*z(n)
//                         x - target, y - filtered target, z - innovative vectors
//    valPredictedGain  Input predicted codebook gain.
//    pCand             pointer to the input pre-searched candidates indexes vector[2].
//                      pCand[0] from  [0,4]
//                      pCand[1] from  [0,8]
//
//    pIdxs             Pointer to the output indexes vector[2].
//    tameProcess           Taming process indicator.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsGainCodebookSearch_G729_32f,(const Ipp32f *pSrcCorr,
       Ipp32f valPredictedGain, const int *pCand, int *pIdxs, int tameProcess))
IPPAPI(IppStatus, ippsGainCodebookSearch_G729D_32f,(const Ipp32f *pSrcCorr,
       Ipp32f valPredictedGain, const int *pCand, int *pIdxs, int tameProcess))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsGainQuant
//  Purpose:    Construct of the excitation for the high rate coder by
//              MultiPulse Maximum Likelihood Quantization (MP-MLQ) of the residual
//              signal
//    pImp      pointer to the input impulse responce of combined filter
//    pSrc      pointer to the input target vector.
//    pDstLoc   pointer to the output pulse location
//    pDstAmp   pointer to the output pulse amplitudes
//    pMaxErr   pointer to the output maximal error
//    pGrid     output grid (even = 0, odd = 1)
//    pAmp      output index of max codebook amplitude
//    Np        input number of pulses
//    isBest    shows whether best gain found (1) or not (0)
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsGainQuant_G723_16s, (const Ipp16s *pImp, const Ipp16s *pSrc,
       Ipp16s *pDstLoc, Ipp16s *pDstAmp, Ipp32s *pMaxErr, Ipp16s *pGrid, Ipp16s *pAmp,
       int Np, int* isBest) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsDecodeGain
//  Purpose:    Decode adaptive and fixed-codebook gains
//    energy       energy of code vector in Q32
//    pPastEnergy  past quantized energies
//    quaIndex     pointer to the gain quantization indexes transmitted:
//                 quaIndex[0] - GA, quaIndex[1] - GB.
//                 NULL for bad frame
//    pGain        Pointer to the vector of decoded gains:
//                 pGain[0] - adaptive and pGain[1] - fixed codebook gains.
//                 For active frame: output vector.
//                 For bad (erased) frame - input/output vector.
//                 Input of gains decoded for previous frame.
//                 See subclause G.729 3.9.1
//    valGainAttenuation
//                Attenuation factor for gains. See subclause G.729 E.4.4.3
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsDecodeGain_G729_16s, (Ipp32s energy, Ipp16s *pPastEnergy,
       const Ipp16s *quaIndex, Ipp16s *pGain) )
IPPAPI(IppStatus, ippsDecodeGain_G729I_16s, (Ipp32s energy, Ipp16s valGainAttenuation, Ipp16s *pPastEnergy,
       const Ipp16s *quaIndex, Ipp16s *pGain))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsTiltCompensation
//  Purpose:    Tilt compensation filter
//              G729:  transfer function 1/(1-|mu|) * (1 + mu * 1/z)
//              G723:  transfer function 1 + 0.25*k1*(1/z)
//    pSrc                 pointer to the input vector
//    val                  gain coefficient
//    pDst                 pointer to the output filtered vector
//    pSrcImpulseResponse  Pointer to the impulse response hf(n) in the length of 20, in Q12.
//    pSrcDstSpch          Pointer to the speech x(n), in Q15
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsTiltCompensation_G729E_16s, (Ipp16s val, const Ipp16s *pSrc,
       Ipp16s *pDst) )
IPPAPI( IppStatus, ippsTiltCompensation_G723_32s16s, (Ipp16s val, const Ipp32s *pSrc,
       Ipp16s *pDst) )

IPPAPI (IppStatus, ippsTiltCompensation_G729_16s,(const Ipp16s * pSrcImpulseResponse,
                                        Ipp16s * pSrcDstSpch))
IPPAPI (IppStatus, ippsTiltCompensation_G729A_16s,
       (const Ipp16s * pSrcLPC,Ipp16s * pSrcDstFltResidual))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsLongTermPostFilter
//  Purpose:    Long-term post G729 filtering
//    valDelay        pitch delay
//    gammaFactor     the LTP weighting factor
//    pSrcSpch        Pointer to the resconstructed speech s[n]
//    pSrcLPC         Pointer to weighted LP coff a'[i]
//    pSrcDstResidual Pointer to LP residual signal.
//    pDstFltResidual Pointer to output filtered residual signal.
//    pResultVoice    Pointer to the voice information.
//    frameType       The type of the frame (1 - active, 2 - SID, 0 - untransmitted).
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsLongTermPostFilter_G729_16s,(Ipp16s gammaFactor, int valDelay,
       const Ipp16s *pSrcDstResidual, Ipp16s *pDstFltResidual, Ipp16s *pResultVoice ))
IPPAPI(IppStatus, ippsLongTermPostFilter_G729A_16s,(Ipp16s valDelay, const Ipp16s * pSrcSpch,
       const Ipp16s * pSrcLPC, Ipp16s * pSrcDstResidual, Ipp16s * pDstFltResidual))
IPPAPI(IppStatus, ippsLongTermPostFilter_G729B_16s,(Ipp16s valDelay, const Ipp16s * pSrcSpch,
       const Ipp16s * pSrcLPC, Ipp16s * pSrcDstResidual, Ipp16s * pDstFltResidual,
       Ipp16s * pResultVoice, Ipp16s frameType))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsShortTermPostFilter
//  Purpose:    Short-term post G729 filtering
//    pSrcDstSpch         Pointer to the short-term filtered speech y(n), in Q15
//    pSrcLPC             Pointer to the quantized LP coefficients in the length of 11, in Q12
//    pDstFltResidual     Pointer to the residual signal x(n) in the length of 40, in Q15.
//    pDstImpulseResponse Pointer to the generated impulse response hf(n)
//                             in the length of 20, in Q12..
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsShortTermPostFilter_G729_16s, (const Ipp16s * pSrcLPC,
        const Ipp16s * pSrcFltResidual, Ipp16s * pSrcDstSpch, Ipp16s * pDstImpulseResponse))
IPPAPI( IppStatus, ippsShortTermPostFilter_G729A_16s,(const Ipp16s * pSrcLPC,
        const Ipp16s * pSrcFltResidual,Ipp16s * pSrcDstSpch))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsPreemphasize
//  Purpose:    Preemphasis post filter
//               H(z) =  1 - gamma z^-1   (G.729/A)
//               H(z) =  1 + gamma z^-1   (GSMAMR)
//    pSrcDst   pointer to the input/output vector
//    gamma     filter coeeficient
//    pMem      pointer to the filter memory of length 1
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsPreemphasize_G729A_16s_I, (Ipp16s gamma, Ipp16s *pSrcDst, int len,
       Ipp16s* pMem) )
IPPAPI( IppStatus, ippsPreemphasize_32f_I,(Ipp32f gamma, Ipp32f *pSrcDst, int len,
       Ipp32f *pMem))
IPPAPI( IppStatus, ippsPreemphasize_G729A_16s, (Ipp16s gamma, const Ipp16s *pSrc, Ipp16s *pDst,
       int len, Ipp16s* pMem) )
IPPAPI( IppStatus, ippsPreemphasize_GSMAMR_16s, (Ipp16s gamma, const Ipp16s *pSrc, Ipp16s *pDst,
       int len, Ipp16s* pMem) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsGainControl
//  Purpose:    Adaptive gain control
//              Compensate for the gain difference between reconstructed speech signal given
//              pSrc (sr) and the postfiltered signal given by pSrcDst (spf)
//                   dst[i] = g[i] * dst[i]
//    pSrc      pointer to the input vector
//    pSrcDst   Pointer to the input post-filtered and output gain compensated signal vector.
//    pSrcDstGain     the gain for the previous subframe
//    pGain     the gain for the previous subframe
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsGainControl_G729_16s_I, (const Ipp16s *pSrc1, Ipp16s *pSrcDst,
       Ipp16s *pGain) )
IPPAPI( IppStatus, ippsGainControl_G729A_16s_I, (const Ipp16s *pSrc1, Ipp16s *pSrcDst,
       Ipp16s *pGain) )
IPPAPI( IppStatus, ippsGainControl_G723_16s_I, (Ipp32s energy, Ipp16s *pSrcDst, Ipp16s *pGain) )

IPPAPI( IppStatus, ippsGainControl_G729_32f_I,(Ipp32f gainScalingVal,
       Ipp32f gainFactor, Ipp32f *pSrcDst, Ipp32f *pGain))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsRandomNoiseExcitation
//  Purpose:    Generation of random noise excitation
//   gain       target sample gain
//   pSrcDst    pointer to the input/output excitation vector
//   pSeed      pointer to the input/output seed for the random generator
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsRandomNoiseExcitation_G729B_16s, (Ipp16s *pSeed, Ipp16s *pExc, int len) )
IPPAPI( IppStatus, ippsRandomNoiseExcitation_G729B_16s32f,(Ipp16s *pSeed, Ipp32f *pExc, int len))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLPCLevinsonDurbin
//  Purpose:     Obtaining of the LPC
//               G.729:  filter 1/1-A(z), LPC in Q12, by solving the set of equation
//                 SUM(i=1,order)a(i)*r(|i-k|) = -r(k)  k=1,..,order
//  Parameters:
//    pSrcAutoCorr          pointer to the autocorrelation vector [order+1]
//    order                 LP order
//    pDstLPC               pointer to the LPC output vector [order+1]
//    pDstRC                pointer to the RC output vector
//                             [2] - ippsLevinsonDurbin_G729B
//                             [order+1] - ippsLevinsonDurbin_G729
//    pResultResidualEnergy pointer to output residual energy in Q15
//
*/
IPPAPI(IppStatus,ippsLevinsonDurbin_G729_32s16s,( const Ipp32s * pSrcAutoCorr,
       int order, Ipp16s * pDstLPC, Ipp16s * pDstRc, Ipp16s * pResultResidualEnergy))
IPPAPI(IppStatus, ippsLevinsonDurbin_G729_32f,(const Ipp32f * pSrcAutoCorr,
       int order, Ipp32f * pDstLpc, Ipp32f * pDstRc, Ipp32f * pResultResidualEnergy))
IPPAPI(IppStatus,ippsLevinsonDurbin_G729B,(const Ipp32s * pSrcAutoCorr,
       Ipp16s * pDstLPC, Ipp16s * pDstRc, Ipp16s * pResultResidualEnergy))


IPPAPI(IppStatus, ippsLevinsonDurbin_G723_16s,
   (const Ipp16s * pSrcAutoCorr, Ipp16s * pValResultSineDtct,
   Ipp16s * pResultResidualEnergy, Ipp16s * pDstLPC))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsIIR16s
//
//  Purpose:    IIR filter
//                  1-A(1/z)/1-B(1/z)
//   pCoeffs    pointer to the input filter coefficients
//   pSrc       pointer to the input speech vector
//   pDst       pointer to the output perceptually weighted speech vector
//   pMem       pointer to the filter memory
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI (IppStatus, ippsIIR16sLow_G729_16s,
        (const Ipp16s *pCoeffs, const Ipp16s *pSrc, Ipp16s *pDst, Ipp16s *pMem))
IPPAPI (IppStatus, ippsIIR16s_G729_16s,
        (const Ipp16s *pCoeffs, const Ipp16s *pSrc, Ipp16s *pDst, Ipp16s *pMem))
IPPAPI( IppStatus, ippsIIR16s_G723_16s32s, (const Ipp16s *pCoeffs, const Ipp16s *pSrc,
       Ipp32s *pDst, Ipp16s *pMem ) )
IPPAPI( IppStatus, ippsIIR16s_G723_16s_I, (const Ipp16s *pCoeffs, Ipp16s *pSrcDst,
       Ipp16s *pMem ) )
IPPAPI( IppStatus, ippsIIR16s_G723_32s16s_Sfs, (const Ipp16s *pCoeffs, const Ipp32s *pSrc,
       int sFs, Ipp16s *pDst, Ipp16s *pMem ) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsHarmonicNoiseSubtract_G723_16s_I
//
//   Purpose:   Do harmonic noise filtering and subtract the result
//              from harmonic noise weighted vector
//   val        the input filter coefficient
//   T          the input filter lag
//   pSrc       pointer to the input vector to filter
//   pSrcDst    pointer to the input/output harmonic noise weighted vector
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsHarmonicNoiseSubtract_G723_16s_I, (Ipp16s val, int T, const Ipp16s *pSrc,
       Ipp16s *pSrcDst) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:    PhaseDispersion
//  Purpose: The filter alters (mainly the phase of) the innovation signal such
//           that a new innovation is created which has the energy more spread over
//           the subframe. The filtering is performed by circular convolution
//           using one of the three stored "semi-random" impulse responses,
//           correspond to different amounts of spreading.
//  Parameters:
//     valPitchGain             pitch gain     Q14
//     valCodebookGain          codebook gain  Q1
//     pSrcExcSignal            input signal
//     pDstFltExcSignal         output signal
//     pSrcDstInnovation        input/output innovation vector
*/
#if !defined( _OWN_BLDPCS )

typedef struct _PhaseDispersion_State_G729D IppsPhaseDispersion_State_G729D;

#endif

IPPAPI(IppStatus, ippsPhaseDispersionGetStateSize_G729D_16s,(int *pSize))
IPPAPI(IppStatus, ippsPhaseDispersionInit_G729D_16s,(IppsPhaseDispersion_State_G729D *pPhDMem))
IPPAPI(IppStatus, ippsPhaseDispersionUpdate_G729D_16s,(
  Ipp16s valPitchGain,
  Ipp16s valCodebookGain,
  IppsPhaseDispersion_State_G729D *pPhDMem
))
IPPAPI(IppStatus, ippsPhaseDispersion_G729D_16s,(
  const Ipp16s *pSrcExcSignal,
  Ipp16s *pDstFltExcSignal,
  Ipp16s valCodebookGain,
  Ipp16s valPitchGain,
  Ipp16s *pSrcDstInnovation,
  IppsPhaseDispersion_State_G729D *pPhDMem
))

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:       ippsWinHybrid_G729E
//  Purpose:    Hybrid window auto-correlation for backward-adaptive analysis.
//              Window is as follows:
//                    s(M-N),s(M-N+1),...,s(M-1),s(M),s(M+1),...,s(M+L-1)
//      M       LPC order for backward adaptation
//      L       number of signal samples in backward adaptation
//      N       number of non-recursive samples in the hybrid window
//              where pSrcSfs[i] is the scale factor of pSrc[i*DIM],...,pSrc[i*DIM+DIM-1]
//
//      pSrcSynthSpeech    input signal for backward-adaptive analysis (35 samples)
//
*/
#if !defined( _OWN_BLDPCS )

typedef struct _WinHybridState_G729E_16s IppsWinHybridState_G729E_16s;
typedef struct _WinHybridState_G729E_32f IppsWinHybridState_G729E_32f;

#endif
IPPAPI(IppStatus, ippsWinHybridGetStateSize_G729E_16s,(int *pSize))
IPPAPI(IppStatus, ippsWinHybridGetStateSize_G729E_32f,(int *pSize))

IPPAPI(IppStatus, ippsWinHybridInit_G729E_16s,(IppsWinHybridState_G729E_16s *pMem))
IPPAPI(IppStatus, ippsWinHybridInit_G729E_32f,(IppsWinHybridState_G729E_32f *pMem))

IPPAPI(IppStatus, ippsWinHybrid_G729E_16s32s,(const Ipp16s  *pSrcSynthSpeech,
       Ipp32s  *pDstInvAutoCorr, IppsWinHybridState_G729E_16s *pMem))
IPPAPI(IppStatus, ippsWinHybrid_G729E_32f,(const Ipp32f  *pSrcSynthSpeech,
       Ipp32f  *pDstInvAutoCorr, IppsWinHybridState_G729E_32f *pMem))

/* /////////////////////////////////////////////////////////////////////////////
//   Name : ippsAutoCorr_G729B
//   Purpose: Apply window and then compute autocorelation of input speech
//            Equvalent to:
//                 ippsMul_NR_16s_Sfs
//                 ippsAutoCorr_NormE_16s32s
*/
IPPAPI(IppStatus,ippsAutoCorr_G729B,
       (const Ipp16s* pSrcSpch, Ipp16s* pResultAutoCorrExp, Ipp32s* pDstAutoCorr))

/* /////////////////////////////////////////////////////////////////////////////
//   Name : ippsLPCToLSP_G729, ippsLPCToLSP_G729A
//   Purpose: LP to LSP coefficients conversion
*/
IPPAPI( IppStatus, ippsLPCToLSP_G729_16s,
       (const Ipp16s* pSrcLPC, const Ipp16s* pSrcPrevLsp, Ipp16s* pDstLSP) )
IPPAPI( IppStatus, ippsLPCToLSP_G729A_16s,
       (const Ipp16s* pSrcLPC, const Ipp16s* pSrcPrevLsp, Ipp16s* pDstLSP) )
IPPAPI( IppStatus, ippsLPCToLSP_G729_32f,
       (const Ipp32f* pSrcLPC, const Ipp32f* pSrcPrevLsp, Ipp32f* pDstLSP))
IPPAPI( IppStatus, ippsLPCToLSP_G729A_32f,
       (const Ipp32f* pSrcLPC, const Ipp32f* pSrcPrevLsp, Ipp32f* pDstLSP))


/* /////////////////////////////////////////////////////////////////////////////
//   Name : ippsAdaptiveCodebookSearch_G729_16s
//   Purpose: Determination of optimal integer and fractional pitch delay
//            and generation of adaptive codebook vector
//  Parameters:
//    valOpenDelay            Open-loop delay, in the range [18,145].
//    pSrcAdptTarget          Pointer to the target signal for adaptive-codebook
//                            search vector [40].
//    pSrcImpulseResponse     Pointer to the impulse response of weighted synthesis filter
//                            vector [40]
//    pSrcDstPrevExcitation   Pointer to the previous and updated excitation vector [194].
//    pDstDelay               Pointer to the integer delay and fraction delay vector [2].
//    pDstAdptVector          Pointer to the adaptive vector [40].
//    subFrame                Subframe number, either 0 or 1.*/
IPPAPI( IppStatus, ippsAdaptiveCodebookSearch_G729_16s, (Ipp16s valOpenDelay,
        const Ipp16s * pSrcAdptTarget, const Ipp16s * pSrcImpulseResponse,
        Ipp16s * pSrcDstPrevExcitation, Ipp16s * pDstDelay,
        Ipp16s * pDstAdptVector, Ipp16s subFrame))
IPPAPI( IppStatus, ippsAdaptiveCodebookSearch_G729A_16s, (Ipp16s valOpenDelay,
        const Ipp16s * pSrcAdptTarget, const Ipp16s * pSrcImpulseResponse,
        Ipp16s * pSrcDstPrevExcitation, Ipp16s * pDstDelay,
        Ipp16s * pDstAdptVector, Ipp16s subFrame))
IPPAPI( IppStatus, ippsAdaptiveCodebookSearch_G729D_16s, (Ipp16s valOpenDelay,
        const Ipp16s * pSrcAdptTarget, const Ipp16s * pSrcImpulseResponse,
        Ipp16s * pSrcDstPrevExcitation, Ipp16s subFrame,  Ipp16s * pDstDelay ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsFilteredExcitation_G729
//  Purpose:     computes filtered excitation
//  Arguments:
//    pSrcImpulseResponse    Pointer to the impulse response of weighted synthesis filter
//                           vector
//    pSrcDstPrevExcitation  Pointer to the previous and updated excitation vector [194].
//    valExc                 Excitation value delayed by pitch lag ( u(-k) )
//    len                    Length of inoput/output vectors
*/
IPPAPI(IppStatus, ippsFilteredExcitation_G729_32f,
       ( const Ipp32f* pSrcImpulseResponse, Ipp32f *pSrcDstPrevExcitation, int len, Ipp32f valExc))
/* /////////////////////////////////////////////////////////////////////////////
//   Name : ippsLSPQuant_G729_16s
//   Purpose: LSP quantization
//            Is equvalent to:
//                 ippsLSPToLSF_G729_16s
//                 ippsLSFQuant_G729_16s
//                 ippsLSFToLSP_G729_16s
*/
IPPAPI( IppStatus, ippsLSPQuant_G729_16s, (const Ipp16s * pSrcLsp, Ipp16s * pSrcDstPrevFreq,
        Ipp16s * pDstQLsp, Ipp16s * pDstQLspIndex))
IPPAPI (IppStatus, ippsLSPQuant_G729E_16s, (const Ipp16s * pSrcLsp, const Ipp16s * pSrcPrevFreq,
        Ipp16s * pDstQLsf, Ipp16s * pDstQLsp, Ipp16s * pDstQLspIndex))
IPPAPI (IppStatus, ippsLSPQuant_G729E_32f, (const Ipp32f  *pSrcLsp,  Ipp32f*  pSrcDstPrevFreq, Ipp32f *pDstQLsf,
                    Ipp32f  *pDstQLsp, int  *pDstQLspIndex) )

/* /////////////////////////////////////////////////////////////////////////////
//   Name : ippsAdaptiveCodebookGain_G729_16s
//   Purpose: Compute the adaptive codebook gain
//
//   pSrcImpulseResponse:  Pointer to the impulse response
//                         of the perceptual weighting filter in the length of 40, in Q12.
//   pSrcAdptVector:       Pointer to the adaptive-codebook vector in the length of 40.
//   pSrcLPC:              Pointer to the LPC coefficients of the synthesis filter
//                         in the length of 11, in Q12.
//   pDstFltAdptVector:    Pointer to the output filtered adaptive-codebook vector
//   pSrcFltAdptVector:    Pointer to the input filtered adaptive-codebook vector
//                         in the length of 40.
//   pResultAdptGain:      Pointer to the adaptive-codebook gain in the length of 1, in Q14.
//   pResultAdptGainCoeffs Pointer to the output vector in the length 4 represents
//                         the adaptive-codebook gain as a fraction:
//                                    xy * 2^exp_xy
//                            gain =  -------------      in Q14
//                                    yy * 2^exp_yy
//                         where yy     = pResultAdptGainCoeffs[0]
//                               exp_yy = pResultAdptGainCoeffs[1]
//                               exp_xy = pResultAdptGainCoeffs[2]
//                               exp_xy = pResultAdptGainCoeffs[3]
//                         If xy < 4 then gain = 0;
*/
IPPAPI( IppStatus, ippsAdaptiveCodebookGain_G729_16s, (const Ipp16s * pSrcAdptTarget,
       const Ipp16s * pSrcImpulseResponse, const Ipp16s * pSrcAdptVector,
       Ipp16s * pDstFltAdptVector, Ipp16s * pResultAdptGain))
IPPAPI( IppStatus, ippsAdaptiveCodebookGain_G729A_16s, (const Ipp16s * pSrcAdptTarget,
       const Ipp16s * pSrcLPC, const Ipp16s * pSrcAdptVector, Ipp16s * pDstFltAdptVector,
       Ipp16s * pResultAdptGain))
IPPAPI( IppStatus, ippsAdaptiveCodebookGain_GSMAMR_16s,(const Ipp16s * pSrcAdptTarget,
       const Ipp16s * pSrcFltAdptVector, Ipp16s * pResultAdptGain))
IPPAPI( IppStatus, ippsAdaptiveCodebookGainCoeffs_GSMAMR_16s,(const Ipp16s * pSrcAdptTarget,
       const Ipp16s * pSrcFltAdptVector, Ipp16s * pResultAdptGain,
       Ipp16s * pResultAdptGainCoeffs))
/* /////////////////////////////////////////////////////////////////////////////
//   Name : ippsFFTFwd_RToPerm_GSMAMR_16s
//   Purpose:  This is an implementation of decimation-in-time FFT algorithm for
//           real sequences.
//   pSrcDst    pointer to the input signal/output frequancies vector in Perm format
*/
IPPAPI( IppStatus, ippsFFTFwd_RToPerm_GSMAMR_16s_I, (Ipp16s *pSrcDst))
/* /////////////////////////////////////////////////////////////////////////////
//   Name : ippsAutoCorr_G723_16s
//   Purpose: Apply window and then compute autocorelation of input speech
//            Equvalent to:
//                 ippsAutoScale_16s
//                 ippsMul_NR_16s_ISfs
//                 ippsAutoCorr_NormE_G723_16s
*/

IPPAPI(IppStatus, ippsAutoCorr_G723_16s,(const Ipp16s * pSrcSpch,
   Ipp16s * pResultAutoCorrExp, Ipp16s * pDstAutoCorr))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLPCToLSF_G723_16s
//  Purpose:     LSP to LSF conversion normalized
//               pLSF[i] = arccos(pLSP[i]);  i=0,...,10
//    pSrcLPC     pointer to the LPC input vector
//    pSrcPrevLSF pointer to previous normalized LSF coefficients
//    pDstLSF     pointer to the LSF output vector of values 15 bit scaled in range [0:0.5]
//  Parameters:
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsLPCToLSF_G723_16s,(const Ipp16s * pSrcLPC,
   const Ipp16s * pSrcPrevLSF, Ipp16s * pDstLSF))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsHarmonicSearch_G723_16s
//  Purpose:      This function searches the harmonic delay and harmonic gain for the harmonic noise shaping filter
//                 from the weighted speech and open loop pitch.
//    valOpenDelay          Open loop pitch
//    pSrcWgtSpch           Pointer to the weighted speech in the length of 205. The pointer points to the
//                           location of 146
//    pResultHarmonicDelay  Pointer to the harmonic delay
//    pResultHarmonicGain   Pointer to the harmonic gain
//  Parameters:
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsHarmonicSearch_G723_16s,(Ipp16s valOpenDelay, const Ipp16s * pSrcWgtSpch,
Ipp16s * pResultHarmonicDelay, Ipp16s * pResultHarmonicGain))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsAdaptiveCodebookSearch_G723
//  Purpose:      This function searches for the close loop pitch and adaptive gain index.
//    valBaseDelay         Base delay
//    pSrcAdptTarget       Pointer to the adaptive target signal in the length of 60.
//    pSrcImpulseResponse  Pointer to the impulse response in the length of 60.
//    pSrcPrevExcitation   Pointer to the previous excitation in the length of 145.
//    pSrcPrevError        Pointer to the previous error in the length of 5, in 32-bit format.
//    pResultCloseLag      Pointer to the lag of close pitch
//    pResultAdptGainIndex Pointer to the index of adaptive gain
//    subFrame             Subframe number
//    sineDtct             Sine circumstance.
//    bitRate              Transmit bit rate
//  Parameters:
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI (IppStatus, ippsAdaptiveCodebookSearch_G723,(
   Ipp16s valBaseDelay,
   const Ipp16s * pSrcAdptTarget,
   const Ipp16s * pSrcImpulseResponse,
   const Ipp16s * pSrcPrevExcitation,
   const Ipp32s * pSrcPrevError,
   Ipp16s * pResultCloseLag,
   Ipp16s * pResultAdptGainIndex,
   Ipp16s subFrame,
   Ipp16s sineDtct,
   IppSpchBitRate bitRate))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsDecodeAdaptiveVector_G723_16s
//  Purpose:      This function decodes the adaptive vector from excitation,
//                close loop pitch, adaptive gain index and bit rate.
*/
IPPAPI (IppStatus, ippsDecodeAdaptiveVector_G723_16s,(
        Ipp16s valBaseDelay,
        Ipp16s valCloseLag,
        Ipp16s valAdptGainIndex,
        const Ipp16s * pSrcPrevExcitation,
        Ipp16s * pDstAdptVector,
        IppSpchBitRate bitRate))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsLSFToLPC_G723_16s
//  Purpose:      This function converts a set of 10-order LSF coefficients to LPC coefficients.
//            Equvalent to:
//                 ippsLSFToLPC_G723_16s_I
*/
IPPAPI (IppStatus, ippsLSFToLPC_G723_16s,(const Ipp16s * pSrcLSF, Ipp16s * pDstLPC))
IPPAPI( IppStatus, ippsLSFToLPC_G723_16s_I, (Ipp16s *pLSFLPC) )

/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsLSFQuant_G723_16s32s
//  Purpose:      This function searches for the close loop pitch and adaptive gain index.
//    pSrcLSF           Pointer to LSF coefficients
//    pSrcPrevLSF       Pointer to previous LSF coefficients
//    pResultQLSFIndex  Pointer to combined index of quantized LSF coefficients.
//  Parameters:
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsLSFQuant_G723_16s32s,(const Ipp16s * pSrcLSF, const Ipp16s *pSrcPrevLSF,
                                       Ipp32s * pResultQLSFIndex))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsACELPFixedCodebookSearch_G723_16s
//  Purpose:      TThis function searches for the ACELP fixed codebook for the excitation for 5.3 Kbps bit rate.
//            Equvalent to:
//                 ippsFixedCodebookSearch_G723_16s
*/
IPPAPI (IppStatus, ippsACELPFixedCodebookSearch_G723_16s,(
        const Ipp16s * pSrcFixedCorr,
        const Ipp16s * pSrcMatrix,
        Ipp16s * pDstFixedSign,
        Ipp16s * pDstFixedPosition,
        Ipp16s * pResultGrid,
        Ipp16s * pDstFixedVector,
        Ipp16s * pSearchTimes))
IPPAPI( IppStatus, ippsACELPFixedCodebookSearch_G723_32s16s,(
        const Ipp16s * pSrcFixedCorr,
        Ipp32s * pSrcDstMatrix,
        Ipp16s * pDstFixedSign,
        Ipp16s * pDstFixedPosition,
        Ipp16s * pResultGrid,
        Ipp16s * pDstFixedVector,
        Ipp16s * pSearchTimes))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsMPMLQFixedCodebookSearch_G723
//
// Purpose:       This function searches for the MP-MLQ fixed-codebook for the excitation for 6.3Kbps bit rate.
// valBaseDelay        - Base delay, in Q0.
// pSrcImpulseResponse - Pointer to the impulse response in the length of 60.
// pSrcResidualTarget  - Pointer to the residue target signal in the length of 60.
// pDstFixedVector     - Pointer to the fixed codebook vector in the length of 60.
// pResultGrid         - Pointer to the begin grid location, in Q0, 0 or 1.
// pResultTrainDirac   - Pointer to the flag if train Dirac function used, 0: unused, 1: used.
// pResultAmpIndex     - Pointer to the index of quantized amplitude, in Q0.
// pResultAmplitude    - Pointer to the amplitude of the fixed codebook vector.
// pResultPosition     - Pointer to the position of fixed codebook vector, which amplitude is not equal
//                        to 0, in Q0.
// subFrame            - Subframe number, in Q0, from 0 to 3.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI (IppStatus, ippsMPMLQFixedCodebookSearch_G723,(
             Ipp16s valBaseDelay,
             const Ipp16s * pSrcImpulseResponse,
             const Ipp16s * pSrcResidualTarget,
             Ipp16s * pDstFixedVector,
             Ipp16s * pResultGrid,
             Ipp16s * pResultTrainDirac,
             Ipp16s * pResultAmpIndex,
             Ipp16s * pResultAmplitude,
             Ipp32s * pResultPosition,
             Ipp16s subFrame))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsSynthesisFilter_G723_16s
//
// Purpose:       function implements the LPC synthesis filter.
// pSrcLPC      - Pointer to the LPC coefficients in the length of 10, in Q13.
// pSrcResidual - Pointer to the residual signal in the length of 60.
// pSrcDstIIRState - Pointer to the history of synthesized speech signal in the
//                 length of 10.
// pDstSpch     - Pointer to the output speech signal in the length of 60.
// pMem           pointer to the filter memory
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsSynthesisFilter_G723_16s32s, (const Ipp16s *pQntLPC,  const Ipp16s *pSrc,
       Ipp32s *pDst, Ipp16s *pMem ) )

IPPAPI(IppStatus, ippsSynthesisFilter_G723_16s, (const Ipp16s *pSrcLPC, const Ipp16s *pSrcResidual,
                   Ipp16s *pSrcDstIIRState, Ipp16s *pDstSpch))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsPitchPostFilter_G723_16s
//
// Purpose:       function calculates the coefficients of the pitch post filter..
// valBaseDelay - Base delay, in Q0.
// pSrcResidual - Pointer to the residual signal in the length of 365.
//                 The pointer points to the location of 146.
// subFrame     - Subframe number, in Q0, from 0 to 3.
// bitRate      - Transmit bit rate, IPP_SPCHBR_6300 stands for 6.3 Kbps
//                 and IPP_SPCHBR_5300 stands for 5.3 Kbps.
// pResultDelay - Point to the delay of the pitch post filter, in Q0.
// pResultPitchGain - Point to the gain of the pitch post filter, in Q15.
// pResultScalingGain - Point to the scaling gain of the pitch post filter, in Q15.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsPitchPostFilter_G723_16s, (Ipp16s valBaseDelay, const Ipp16s *pSrcResidual,
                    Ipp16s *pResultDelay, Ipp16s *pResultPitchGain, Ipp16s *pResultScalingGain,
                    Ipp16s subFrame, IppSpchBitRate bitRate))

/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsAutoCorr_GSMAMR_16s32s
//
// Purpose:       Compute autocorrelations of signal with windowing and
//                 Lag windowing
// pSrcSpch     - Pointer to the input speech vector (240 samples),
//                 represented using Q15.0.
// mode         - Bit rate specifier. Values between IPP_SPCHBR_4750 and
//                 IPP_SPCHBR_12200 are valid.
// pDstAutoCorr - Pointer to the autocorrelation coefficients, of length 22.
//                 For 12.2 kbps mode, elements 0 ~ 10 contain the first
//                 set of autocorrelation lags, and elements 11 ~ 21
//                 contain the second set of autocorrelation lags.
//                 For all other modes there is only one set of autocorrelation
//                 lags contained in vector elements 0 ~ 10.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsAutoCorr_GSMAMR_16s32s,
      (const Ipp16s *pSrcSpch, Ipp32s *pDstAutoCorr,IppSpchBitRate mode))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsLevinsonDurbin_GSMAMR_32s16s
//
// Purpose:       Calculates the 10th-order LP coefficients from the autocorrelation lags using the Levinson-Durbin
//                 algorithm.
// pSrcAutoCorr - Pointer to the autocorrelation coefficients, a vector of length of 11.
// pSrcDstLPC   - Pointer to the LP coefficients associated with
//                 the previous frame, a vector of length 11, represented using Q3.12.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsLevinsonDurbin_GSMAMR_32s16s,
                  (const Ipp32s *pSrcAutoCorr, Ipp16s *pSrcDstLPC))
#define ippsLevinsonDurbin_GSMAMR ippsLevinsonDurbin_GSMAMR_32s16s
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsLPCToLSP_GSMAMR_16s
//
// Purpose:       Converts a set of 10th-order LP coefficients to
//                 an equivalent set of line spectrum pairs (LSPs).
// pSrcLPC      - Pointer to 11-element LP coefficient vector, represented using Q3.12.
// pSrcPrevLsp  - Pointer to the 10-element LSP coefficient vector associated
//                 with the previous frame, represented using Q0.15.
// pDstLsp      - Pointer to the 10-element LSP coefficient vector, represented using Q0.15.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI(IppStatus, ippsLPCToLSP_GSMAMR_16s,
                  (const Ipp16s * pSrcLPC, const Ipp16s * pSrcPrevLsp, Ipp16s * pDstLsp))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsLSPToLPC_GSMAMR_16s
//
// Purpose:       Converts a set of 10th-order LSPs to LP coefficients.
// pSrcLsp      - Pointer to the 10-element LSP coefficient vector, represented using Q0.15.
// pDstLPC      - Pointer to the 11-element LP coefficient vector, represented using Q3.12.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsLSPToLPC_GSMAMR_16s, (const Ipp16s *pSrcLsp, Ipp16s *pDstLPC))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsLSPQuant_GSMAMR_16s
//
// Purpose:       Quantizes the LSP coefficient vector, then obtains quantized LSP codebook indices.
// pSrcLsp      - Pointer to the unquantized 20-element LSP vector, represented using Q0.15. For
//                 12.2 kbps frames, the first LSP set is contained in vector elements 0 ~ 9, and the second LSP
//                 set is contained in vector elements 10 ~ 19. For all other bit rates, only elements 0 ~ 9 are valid
//                 and used for the quantization.
// pSrcDstPrevQLSFResidual  - Pointer to the 10-element quantized LSF residual from the previous
//                 frame, represented using Q0.15.
// pDstQLsp     - Pointer to the 20-element quantized LSP vector, represented using Q0.15. For 12.2
//                 kbps frames, elements 0 to 9 contain the first quantized LSP set, and elements 10 to 19 contain
//                 the second quantized LSP set. For all other bit rates there is only one LSP set contained in
//                 elements 0 to 9.
// pDstQLspIndex - Pointer to the 5-element vector of quantized LSP indices. For 12.2Kbps
//                 frames, all five elements contain valid data; for all other bit rates, only the first three elements
//                 contain valid indices.
// mode         - Bit rate specifier. The enumerated values of IPP_SPCHBR_4750 to
//                 IPP_SPCHBR_12200 are valid.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsLSPQuant_GSMAMR_16s, (const Ipp16s *pSrcLsp,
                  Ipp16s *pSrcDstPrevQLSFResidual, Ipp16s *pDstQLsp,
                  Ipp16s *pDstQLspIndex, IppSpchBitRate mode))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsEncDTXSID_GSMAMR_16s
//
// Purpose:       This function is called only when the current frame is a DTX frame. It extracts the needed
//                 parameters for the SID frame: LSF quantization parameter and the energy index parameter. If the
//                 SID flag is off, no operation is needed, and all the parameters are copied from last frame.
// pSrcLspBuffer - Pointer to the LSP coefficients of eight consecutive frames marked with
//                 VAD = 0, in the length of 80, in Q15.
// pSrcLogEnergyBuffer - Pointer to the log energy coefficients of eight consecutive frames
//                 marked with unvoiced, in the length of 8, in Q10.
// pValResultLogEnergyIndex - Pointer log energy index of last frame, in Q2.
// pValResultDtxLSFRefIndex - Pointer to the LSF quantization reference index of last frame.
// pSrcDstDtxQLSFIndex - Pointer to the LSF residual quantization indices of last frame, in the
//                 length of 3.
// pSrcDstPredQErr - Pointer to the fixed gain prediction error of four previous subframes for
//                 non-12.2 Kbps modes, in the length of 4, in Q10.
// pSrcDstPredQErrMR122 - Pointer to the fixed gain prediction error of four previous
//                 subframes for 12.2 Kbps, in the length of 4, in Q10.
// sidFLag      - The SID flag of the current frame. If it is set to 1, the current frame is a SID frame,
//                 and the function will extract the LSF and energy parameters. If it is set to 0, the LSF and
//                 energy parameters will copy from previous frame.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsEncDTXSID_GSMAMR_16s, (const Ipp16s *pSrcLspBuffer,
                  const Ipp16s *pSrcLogEnergyBuffer, Ipp16s *pValResultLogEnergyIndex,
                  Ipp16s *pValResultDtxLSFRefIndex, Ipp16s *pSrcDstDtxQLSFIndex,
                  Ipp16s *pSrcDstPredQErr, Ipp16s *pSrcDstPredQErrMR122,
                  Ipp16s sidFlag))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsQuantLSPDecode_GSMAMR_16s
//
// Purpose:       Decodes quantized LSPs from the received codebook index if the
//                 errors are not detected on the received frame. Otherwise, the
//                 function recovers the quantized LSPs from previous quantized
//                 LSPs using linear interpolation.
// pSrcQLspIndex - Pointer to the five-element vector containing codebook indices
//                 of the quantized LSPs.
// pSrcDstPrevQLSFResidual - Pointer to the 10-element quantized LSF residual from
//                 the previous frame, represented using Q0.15.
// pSrcDstPrevQLSF - Pointer to the 10-element quantized LSF vector from the previous
//                 frame, represented using Q0.15.
// pSrcDstPrevQLsp - Pointer to the 10-element quantized LSP vector from the previous
//                 frame, represented using Q0.15.
// pDstQLsp      - Pointer to a 40-element vector containing four subframe LSP sets.
// bfi           - Bad frame indicator; "0" signifies a good frame; all other values
//                  signify a bad frame.
// mode          - Bit rate specifier.
// Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsQuantLSPDecode_GSMAMR_16s, (const Ipp16s *pSrcQLspIndex,
                  Ipp16s *pSrcDstPrevQLSFResidual, Ipp16s *pSrcDstPrevQLSF,
                  Ipp16s *pSrcDstPrevQLsp, Ipp16s *pDstQLsp, Ipp16s bfi,
                  IppSpchBitRate mode))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsEncDTXHandler_GSMAMR_16s
//
// Purpose:       Function determines the SID flag of current frame, and it determines
//                 whether the current frame should use DTX encoding.
// pValResultHangOverCount - Pointer to the DTX hangover count. When initialized or reset,
//                 it is set to 0.
// pValResultDtxElaspCount - Pointer to elapsed frame count since last non-DTX frame.
//                 When initialized or reset, it is set 0.
// pValResultUsedMode - Pointer to the transmission mode.
// pResultSidFlag - Pointer to the output SID flag, "1" indicates a SID frame, and "0"
//                 indicates a non-SID frame.
// vadFlag        - This is the VAD flag of the current frame, if it is set 1, the current
//                  frame is marked with voiced, and if it is set to 0, it is marked with
//                  unvoiced.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsEncDTXHandler_GSMAMR_16s, (Ipp16s *pValResultHangOverCount,
                  Ipp16s *pValResultDtxElapseCount, Ipp16s *pValResultUsedMode,
                  Ipp16s *pResultSidFlag, Ipp16s vadFlag))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsEncDTXBuffer_GSMAMR_16s
//
// Purpose:       Function buffer the LSP coefficients and previous log energy coefficients.
// pSrcSpch     - Pointer to the input speech signal, in the length of 160, in Q15.0.
// pSrcLsp      - Pointer to the LSP for this frame, in the length of 10, in Q0.15.
// pValResultUpdateIndex - Pointer to the previous memory update index. It is a value
//                 circularly increased between 0 and 7.
// pSrcDstLspBuffer - Pointer to the LSP coefficients of eight previous frames, in the
//                 length of 80, in Q0.15.
// pSrcDstLogEnergyBuffer - Pointer to the logarithm energy coefficients of eight previous
//                 frames,inthelength of 8,in Q5.10.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsEncDTXBuffer_GSMAMR_16s, (const Ipp16s * pSrcSpch,
                  const Ipp16s *pSrcLsp, Ipp16s *pValResultUpdateIndex,
                  Ipp16s *pSrcDstLspBuffer, Ipp16s *pSrcDstLogEnergyBuffer))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsDecDTXBuffer_GSMAMR_16s
//
// Purpose:       Function buffer the LSF coefficients and previous log energy coefficients.
// pSrcSpch     - Pointer to the input speech signal, in the length of 160, in Q15.0.
// pSrcLSF      - Pointer to the LSF for this frame, in the length of 10, in Q0.15.
// pValResultUpdateIndex - Pointer to the previous memory update index. It is a value
//                 circularly increased between 0 and 7.
// pSrcDstLSFBuffer - Pointer to the LSF coefficients of eight previous frames, in the
//                 length of 80, in Q0.15.
// pSrcDstLogEnergyBuffer - Pointer to the logarithm energy coefficients of eight previous
//                 frames,inthelength of 8,in Q5.10.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsDecDTXBuffer_GSMAMR_16s, (const Ipp16s *pSrcSpch,
                  const Ipp16s *pSrcLSF, Ipp16s *pValResultUpdateIndex,
                  Ipp16s *pSrcDstLSFBuffer, Ipp16s *pSrcDstLogEnergyBuffer))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsAlgebraicCodebookSearch_GSMAMR_16s
//
//   Purpose:   Fixed (algebraic) codebook search functions
//   valIntPitchLag         pitch lag
//   valBoundQAdptGain      pitch gain
//   pSrcFixedTarget        target vector
//   pSrcLtpResidual        long term prediction residual
//   pSrcDstImpulseResponse impulse response of weighted synthesis
//                          filter h[-L_subfr..-1] must be set to zero
//   pDstFixedVector        innovative codebook
//   pDstFltFixedVector     filtered fixed codebook excitation
//   pDstEncPosSign         signs of the pulses
//   subFrame               subframe number
//   mode                   coder mode
//   pBuffer                pouinter to the internal memory buffer
//  Returns:                IppStatus
//      ippStsNoErr         if no error
*/
IPPAPI( IppStatus, ippsAlgebraicCodebookSearch_GSMAMR_16s, (Ipp16s valIntPitchLag, Ipp16s valBoundQAdptGain,
       const Ipp16s *pSrcFixedTarget, const Ipp16s *pSrcLtpResidual, Ipp16s *pSrcDstImpulseResponse,
       Ipp16s *pDstFixedVector, Ipp16s *pDstFltFixedVector, Ipp16s *pDstEncPosSign,
       Ipp16s subFrame, IppSpchBitRate mode) )
IPPAPI(IppStatus, ippsAlgebraicCodebookSearchEX_GSMAMR_16s,
      (Ipp16s   valIntPitchLag,   Ipp16s valBoundQAdptGain,
       const Ipp16s * pSrcFixedTarget, const Ipp16s * pSrcLtpResidual,
       Ipp16s * pSrcDstImpulseResponse, Ipp16s   * pDstFixedVector,
       Ipp16s * pDstFltFixedVector, Ipp16s * pDstEncPosSign,
       Ipp16s subFrame, IppSpchBitRate mode, Ipp32s * pBuffer))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsFixedCodebookDecode_GSMAMR_16s
//
//   Purpose:   Fixed codebook vector decode functions
//   pSrcFixedIndex         pointer to the fixed codebook index vector
//   pDstFixedVector        pointer to the 40-element fixed codebook vector
//   subFrame               subframe number
//   mode                   coder mode
//  Returns:                IppStatus
//      ippStsNoErr         if no error
*/
IPPAPI (IppStatus, ippsFixedCodebookDecode_GSMAMR_16s,
        (const Ipp16s   *pSrcFixedIndex,
        Ipp16s          *pDstFixedVector,
        Ipp16s          subFrame,
        IppSpchBitRate  mode) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsOpenLoopPitchSearchNonDTX_GSMAMR_16s
//
//   Purpose:   Computes the open-loop pitch lag (as well as optimal pitch gain for 10.2 kbps frames only) when
//              both DTX and VAD are disabled.
//   pSrcWgtLPC1                Pointer to the 44-element vector of weighted LP coefficients
//   pSrcWgtLPC2                Pointer to the 44-element vector of weighted LP coefficients
//   pSrcSpch                   Pointer to the 170-sample input speech vector
//   pValResultPrevMidPitchLag  Pointer to the median filtered pitch lag of the 5 previous voiced
//                              speech half-frames
//   pValResultVvalue           Pointer to the adaptive parameter v
//   pSrcDstPrevPitchLag        Pointer to the five-element vector that contains the pitch lags associated
//                              with the five most recent voiced speech half-frames
//   pSrcDstPrevWgtSpch         Pointer to a 143-element vector containing perceptually weighted
//                              speech from the previous frame
//   pDstOpenLoopLag            Pointer to a two-element vector of open-loop pitch lags.
//   pDstOpenLoopGain           Pointer to a 2-element vector containing optimal open-loop pitch gains.
//   mode                       coder mode
//  Returns:                    IppStatus
//      ippStsNoErr             if no error
*/

IPPAPI (IppStatus, ippsOpenLoopPitchSearchNonDTX_GSMAMR_16s,(
      const Ipp16s * pSrcWgtLPC1,
      const Ipp16s * pSrcWgtLPC2,
      const Ipp16s * pSrcSpch,
      Ipp16s * pValResultPrevMidPitchLag,
      Ipp16s * pValResultVvalue,
      Ipp16s * pSrcDstPrevPitchLag,
      Ipp16s * pSrcDstPrevWgtSpch,
      Ipp16s * pDstOpenLoopLag,
      Ipp16s * pDstOpenLoopGain,
      IppSpchBitRate mode))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsOpenLoopPitchSearchDTXVAD1_GSMAMR_16s
//
//   Purpose:   Extracts an open-loop pitch lag estimate from the weighted input speech when the VAD 1 scheme
//              is enabled
//   pSrcWgtLPC1                Pointer to the 44-element vector of weighted LP coefficients
//   pSrcWgtLPC2                Pointer to the 44-element vector of weighted LP coefficients
//   pSrcSpch                   Pointer to the 170-sample input speech vector
//   pValResultToneFlag         Pointer to the tone flag for the VAD module.
//   pValResultPrevMidPitchLag  Pointer to the median filtered pitch lag of the 5 previous voiced
//                              speech half-frames
//   pValResultVvalue           Pointer to the adaptive parameter v
//   pSrcDstPrevPitchLag        Pointer to the five-element vector that contains the pitch lags associated
//                              with the five most recent voiced speech half-frames
//   pSrcDstPrevWgtSpch         Pointer to a 143-element vector containing perceptually weighted
//                              speech from the previous frame
//   pResultMaxHpCorr           Pointer to the correlation maximum.
//   pDstOpenLoopLag            Pointer to a two-element vector of open-loop pitch lags.
//   pDstOpenLoopGain           Pointer to a 2-element vector containing optimal open-loop pitch gains.
//   mode                       coder mode
//  Returns:                    IppStatus
//      ippStsNoErr             if no error
*/
IPPAPI (IppStatus, ippsOpenLoopPitchSearchDTXVAD1_GSMAMR_16s,(
      const Ipp16s * pSrcWgtLPC1,
      const Ipp16s * pSrcWgtLPC2,
      const Ipp16s * pSrcSpch,
      Ipp16s * pValResultToneFlag,
      Ipp16s * pValResultPrevMidPitchLag,
      Ipp16s * pValResultVvalue,
      Ipp16s * pSrcDstPrevPitchLag,
      Ipp16s * pSrcDstPrevWgtSpch,
      Ipp16s * pResultMaxHpCorr,
      Ipp16s * pDstOpenLoopLag,
      Ipp16s * pDstOpenLoopGain,
      IppSpchBitRate mode))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsOpenLoopPitchSearchDTXVAD2_GSMAMR_16s32s
//
//   Purpose:   Extracts an open-loop pitch lag estimate from the weighted input speech when the VAD 2 scheme
//               is enabled
//   pSrcWgtLPC1                Pointer to the 44-element vector of weighted LP coefficients
//   pSrcWgtLPC2                Pointer to the 44-element vector of weighted LP coefficients
//   pSrcSpch                   Pointer to the 170-sample input speech vector
//   pValResultPrevMidPitchLag  Pointer to the median filtered pitch lag of the 5 previous voiced
//                              speech half-frames
//   pValResultVvalue           Pointer to the adaptive parameter v
//   pSrcDstPrevPitchLag        Pointer to the five-element vector that contains the pitch lags associated
//                              with the five most recent voiced speech half-frames
//   pSrcDstPrevWgtSpch         Pointer to a 143-element vector containing perceptually weighted
//                              speech from the previous frame
//   pResultMaxCorr             Pointer to the correlation maximum..
//   pResultWgtEnergy           Pointer to the pitch delayed energy of the weighted speech signal.
//   pDstOpenLoopLag            Pointer to a two-element vector of open-loop pitch lags.
//   pDstOpenLoopGain           Pointer to a 2-element vector containing optimal open-loop pitch gains.
//   mode                       coder mode
//  Returns:                    IppStatus
//      ippStsNoErr             if no error
*/
IPPAPI (IppStatus, ippsOpenLoopPitchSearchDTXVAD2_GSMAMR_16s32s,(
      const Ipp16s * pSrcWgtLPC1,
      const Ipp16s * pSrcWgtLPC2,
      const Ipp16s * pSrcSpch,
      Ipp16s * pValResultPrevMidPitchLag,
      Ipp16s * pValResultVvalue,
      Ipp16s * pSrcDstPrevPitchLag,
      Ipp16s * pSrcDstPrevWgtSpch,
      Ipp32s * pResultMaxCorr,
      Ipp32s * pResultWgtEnergy,
      Ipp16s * pDstOpenLoopLag,
      Ipp16s * pDstOpenLoopGain,
      IppSpchBitRate mode))
#define ippsOpenLoopPitchSearchDTXVAD2_GSMAMR ippsOpenLoopPitchSearchDTXVAD2_GSMAMR_16s32s
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsImpulseResponseTarget_GSMAMR_16s
//
//   Purpose:   Computes the impulse response and target signal required for the adaptive codebook search.
//   pSrcSpch                   Pointer to the 50-element input speech vector, where elements 0 - 9 are from the
//                                previous subframe, and elements 10 - 49 are from the current subframe.
//   pSrcWgtLPC1                Pointer to an 11-element vector of weighted LP coefficients
//   pSrcWgtLPC2                Pointer to an 11-element vector of weighted LP coefficients
//   pSrcQLPC                   Pointer to an 11-element vector of quantized LP coefficients
//   pSrcSynFltState            Pointer to the 10-element vector that contains the state of the synthesis
//                               filter
//   pSrcWgtFltState            Pointer to the 10-element vector that contains the state of the weighting
//                               filter.
//   pDstImpulseResponse        Pointer to the 40-element vector that contains the impulse response.
//   pDstLpResidual             Pointer to the 40-element vector that contains the LP residual.
//   pDstAdptTarget             Pointer to the 40-element vector that contains the adaptive codebook search
//                               target signal.
//  Returns:                    IppStatus
//      ippStsNoErr             if no error
*/
IPPAPI (IppStatus, ippsImpulseResponseTarget_GSMAMR_16s,(
      const Ipp16s * pSrcSpch,
      const Ipp16s * pSrcWgtLPC1,
      const Ipp16s * pSrcWgtLPC2,
      const Ipp16s * pSrcQLPC,
      const Ipp16s * pSrcSynFltState,
      const Ipp16s * pSrcWgtFltState,
      Ipp16s * pDstImpulseResponse,
      Ipp16s * pDstLpResidual,
      Ipp16s * pDstAdptTarget))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsAdaptiveCodebookSearch_GSMAMR_16s
//
//   Purpose:   Performs the adaptive codebook search.
//   pSrcAdptTarget             Pointer to the 40-element adaptive target signal vector,
//   pSrcImpulseResponse        Pointer to the 40-element impulse response of the weighted synthesis
//                               filter.
//   pSrcOpenLoopLag            Pointer to a two-element vector of open-loop pitch lags.
//   pValResultPrevIntPitchLag  Pointer to the previous integral pitch lag.
//   pSrcDstExcitation          Pointer to the 194-element excitation vector.
//   pResultFracPitchLag        Pointer to the fractional pitch lag obtained during the adaptive codebook
//                               search.
//   pResultAdptIndex           Pointer to the coded closed-loop pitch index.
//   pDstAdptVector             Pointer to the 40-sample adaptive codebook vector.
//   subFrame                   subframe number
//   mode                       coder mode
//  Returns:                    IppStatus
//      ippStsNoErr             if no error
*/
IPPAPI (IppStatus, ippsAdaptiveCodebookSearch_GSMAMR_16s,(
      const Ipp16s * pSrcAdptTarget,
      const Ipp16s * pSrcImpulseResponse,
      Ipp16s * pSrcOpenLoopLag,
      Ipp16s * pValResultPrevIntPitchLag,
      Ipp16s * pSrcDstExcitation,
      Ipp16s * pResultFracPitchLag,
      Ipp16s * pResultAdptIndex,
      Ipp16s * pDstAdptVector,
      Ipp16s   subFrame,
      IppSpchBitRate mode))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsAdaptiveCodebookDecode_GSMAMR_16s
//
//   Purpose:   This function decodes the adaptive codebook parameters transmitted by the encoder, and then
//                applies them to interpolate an adaptive codebook vector.
//   valAdptIndex               Adaptive codebook index.
//   pValResultPrevIntPitchLag  Pointer to the previous integer pitch lag.
//   pValResultLtpLag           Pointer to the LTP-Lag value.
//   pSrcDstExcitation          Pointer to the 194-element excitation vector.
//   pResultIntPitchLag         Pointer to the 194-element excitation vector.
//   pDstAdptVector             Pointer to the fractional pitch lag obtained during the adaptive codebook
//   subFrame                   subframe number
//   bfi                        Bad frame indicator. "0" signifies a good frame; any other value signifies a bad frame.
//   inBackgroundNoise          Flag set when the previous frame is considered to contain background
//                               noise and only shows minor energy level changes.
//   voicedHangover             Counter used to monitor the time since a frame was presumably voiced.
//   mode                       coder mode
//  Returns:                    IppStatus
//      ippStsNoErr             if no error
*/
IPPAPI (IppStatus ,ippsAdaptiveCodebookDecode_GSMAMR_16s,(
      Ipp16s valAdptIndex,
      Ipp16s * pValResultPrevIntPitchLag,
      Ipp16s * pValResultLtpLag,
      Ipp16s * pSrcDstExcitation,
      Ipp16s * pResultIntPitchLag,
      Ipp16s * pDstAdptVector,
      Ipp16s subFrame,
      Ipp16s bfi,
      Ipp16s inBackgroundNoise,
      Ipp16s voicedHangover,
      IppSpchBitRate mode))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsPostFilter_GSMAMR_16s
//
//   Purpose:   This function decodes the adaptive codebook parameters transmitted by the encoder, and then
//                applies them to interpolate an adaptive codebook vector.
//   pSrcQLPC                   Pointer to the reconstructed LP coefficients, in the length of 44.
//   pSrcSpch                   Pointer to the start position of the input speech signal for current frame.
//   pValResultPrevResidual     Pointer to the last output of the FIR filter of the formant filter for
//                               previous subframe.
//   pValResultPrevScalingGain  Pointer to the scaling factor b of the last signal for the previous
//                               subframe.
//   pSrcDstFormantFIRState     Pointer to the state of the FIR part of the formant filter, in the
//                               length of 10.
//   pSrcDstFormantIIRState     Pointer to the state of the IIR part of the formant filter, in the length
//                               of 10.
//   pDstFltSpch                Pointer to the filtered speech, in the length of 160.
//   mode                       coder mode
//  Returns:                    IppStatus
//      ippStsNoErr             if no error
*/
IPPAPI (IppStatus, ippsPostFilter_GSMAMR_16s,(
        const Ipp16s * pSrcQLPC,
        const Ipp16s * pSrcSpch,
        Ipp16s * pValResultPrevResidual,
        Ipp16s * pValResultPrevScalingGain,
        Ipp16s * pSrcDstFormantFIRState,
        Ipp16s * pSrcDstFormantIIRState,
        Ipp16s * pDstFltSpch,
        IppSpchBitRate mode))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsVAD1_GSMAMR_16s
//
//   Purpose:   Voice Activity Detection (VAD) for AMR (option 1) functions
//   pSrcSpch               pointer to the input speech signal, in the length of 160
//   pSrcDstVad1State       pointer to the VAD Option 1 history variables
//   pResultVadFlag         pointer to the VAD flag of this frame
//   maxHpCorr              best_corr_hp value of previous frame
//   toneFlag               tone flag
//  Returns:                IppStatus
//      ippStsNoErr         if no error
*/
IPPAPI (IppStatus, ippsVAD1_GSMAMR_16s,
        (const Ipp16s *pSrcSpch,
         IppGSMAMRVad1State *pSrcDstVad1State,
         Ipp16s *pResultVadFlag,
         Ipp16s maxHpCorr,
         Ipp16s toneFlag) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsVAD2_GSMAMR_16s
//
//   Purpose:   Voice Activity Detection (VAD) for AMR (option 2) functions
//   pSrcSpch               pointer to the input speech signal, in the length of 160
//   pSrcDstVad2State       pointer to the VAD Option 2 history variables
//   pResultVadFlag         pointer to the VAD flag of this frame
//   ltpFlag                LTP_flag value, which is generated by the comparison
//                          of the long-term prediction to a constant threshold LTP_THLD.
//  Returns:                IppStatus
//      ippStsNoErr         if no error
*/
IPPAPI (IppStatus, ippsVAD2_GSMAMR_16s,
        (const Ipp16s * pSrcSpch,
        IppGSMAMRVad2State *pSrcDstVad2State,
        Ipp16s *pResultVadFlag,
        Ipp16s ltpFlag) )
/* /////////////////////////////////////////////////////////////////////////////
//                         G.722.1 related functions
///////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsDCTFwd_G722, ippsDCTInv_G722
// Purpose:    Computes the forward or inverse discrete cosine transform (DCT)
//             of a signal.
// Parameters:
//    pSrc     Pointer to the source vector[320].
//    pDst     Pointer to the destination vector[320].
// Returns:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrc or pDst pointer is null.
*/
IPPAPI( IppStatus, ippsDCTFwd_G722_16s, (const Ipp16s *pSrc, Ipp16s *pDst))

IPPAPI( IppStatus, ippsDCTInv_G722_16s, (const Ipp16s *pSrc, Ipp16s *pDst))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsDecomposeMLTToDCT_G722
// Purpose:    Decompose MLT transform input signal to form of the DCT transform
//             input signal.
// Parameters:
//    pSrcSpch             Pointer to the source vector[320].
//    pSrcSpchOld          Pointer to the source/destination vector[320] of speech
//                         samples of previous frame.
//    pDstSpchDecomposed   Pointer to the destination vector[320].
// Returns:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrcSpch or pDstSpch
//                      or pSrcSpchOld pointer is null.
*/
IPPAPI( IppStatus, ippsDecomposeMLTToDCT_G722_16s, (const Ipp16s *pSrcSpch,
       Ipp16s *pSrcDstSpchOld, Ipp16s *pDstSpchDecomposed))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsDecomposeDCTToMLT_G722_16s
// Purpose:    Decompose IDCT output signal to form of the  MLT transform output signal.
// Parameters:
//    pSrcSpchDecomposed      Pointer to the source vector[320].
//    pSrcSpchDecomposedOld   Pointer to the source/destination vector[160] of
//                            decomposed speech samples of previous frame.
//    pDstSpch                Pointer to the destination vector[320].
// Returns:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrcSpchDecomposed or
//                      pSrcSpchDecomposedOld or pDstSpch pointer is null.
*/
IPPAPI( IppStatus, ippsDecomposeDCTToMLT_G722_16s, (const Ipp16s *pSrcSpchDecomposed,
       Ipp16s *pSrcDstSpchDecomposedOld, Ipp16s *pDstSpch))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsHuffmanEncode_G722
// Purpose:    Performs Huffman encoding of the quantized amplitude envelope indexes.
// Parameters:
//    category          The category of MLT region in range of [0-7]
//    qntAmpEnvIndex    The quantized amplitude envelope index in range of [0-63]
//    pSrcMLTCoeffs     Pointer to the source vector[20] of raw MLT coefficients.
//    pDstCode          Pointer to the output Huffman code.
//    pCodeLength       Pointer to output Huffman code length in bit.
// Returns:
//    ippStsNoErr          Indicates no error.
//    IppStsNullPtrErr     Indicates an error when the pSrcMLTCoeffs or pDstCode
//                         or pCodeLength  pointer is null
//    IppStsScaleRangeErr  Indicates an error when category or qntAmpEnvIndex is out of
//                         proper range.
*/
IPPAPI( IppStatus, ippsHuffmanEncode_G722_16s32u, (int category, int qntAmpEnvIndex,
       const Ipp16s *pSrcMLTCoeffs, Ipp32u *pDstCode, int *pCodeLength))
/* /////////////////////////////////////////////////////////////////////////////
//                               G.722.1 end
///////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////////////////////////////////////////////////
//                         G.726 related functions
///////////////////////////////////////////////////////////////////////////// */
#if !defined( _OWN_BLDPCS )

typedef struct _EncoderState_G726_16s IppsEncoderState_G726_16s;
typedef struct _DecoderState_G726_16s IppsDecoderState_G726_16s;

#endif
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsEncodeGetStateSize_G726
//  Purpose:     Query of G726 encoder memory size
//  Parameters:
//    pEncSize   Pointer to the output value of the G726 encoder memory size in bytes
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsEncodeGetStateSize_G726_16s8u,(unsigned int* pEncSize))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsEncodeInit_G726
//  Purpose:       Initializes the memory for the ADPCM encode
//  Parameters:
//    pEncMem      Pointer to the input memory buffer of appropriate size applicable to
//                 store a state of the encoder
//    rate         Encode bit rate of the G.726 encoder: IPP_SPCHBR_16000,
//                 IPP_SPCHBR_24000, IPP_SPCHBR_32000, IPP_SPCHBR_40000.
//  Returns:
//    ippStsBadArgErr   Indicates an error when the rate is not equal to one of the
//                      allowable encoding bit rates:  IPP_SPCHBR_16000, IPP_SPCHBR_24000 or
//                      IPP_SPCHBR_32000,    IPP_SPCHBR_40000.
//    IppStsNullPtrErr   Indicates an error when the memory pointer is null
*/
IPPAPI(IppStatus, ippsEncodeInit_G726_16s8u,
       (IppsEncoderState_G726_16s* pEncMem, IppSpchBitRate rate))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsEncode_G726
//  Purpose:       ADPCM encoding of input speech signal
//  Parameters:
//    pEncMem      Pointer to the encoder state memory
//    pSrc         Pointer to the uniform PCM input speech vector.
//    pDst         Pointer to the ADPCM bit-stream output vector.
//    len          The length of input/output vectors.
//  Returns:
//    ippStsNoErr,      if no errors
//    ippStsBadArgErr   Indicates an error when the len is less or equal to 0.
//    IppStsNullPtrErr   Indicates an error when the pEncMem , pSrc, pDst pointer is null
*/
IPPAPI(IppStatus, ippsEncode_G726_16s8u,
       (IppsEncoderState_G726_16s* pEncMem, const Ipp16s *pSrc, Ipp8u *pDst, unsigned int len))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsEncodeGetStateSize_G726
//  Purpose:     Query of G726 decoder memory size
//  Parameters:
//    pDecSize   Pointer to the output value of the G726 decoder memory size in bytes
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsDecodeGetStateSize_G726_8u16s,(unsigned int* pDecSize))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsEncodeInit_G726
//  Purpose:       Initializes the memory for the ADPCM encode
//  Parameters:
//    pDecMem      Pointer to the input memory buffer of appropriate size applicable to
//                 store a state of the decoder
//    rate         input bit rate of the G.726 decoder: IPP_SPCHBR_16000,
//                 IPP_SPCHBR_24000, IPP_SPCHBR_32000, IPP_SPCHBR_40000.
//    law          Output speech PCM law : IPP_PCM_MULAW, IPP_PCM_ALAW, IPP_PCM_LINEAR
//  Returns:
//    ippStsBadArgErr   Indicates an error when the rate is not equal to one of the
//                      allowable decoding bit rates:  IPP_SPCHBR_16000, IPP_SPCHBR_24000 or
//                      IPP_SPCHBR_32000,
//                      IPP_SPCHBR_40000 or the law is not equal to one othe allowable output PCM:
//                      IPP_PCM_MULAW, IPP_PCM_ALAW, IPP_PCM_LINEAR.
//    IppStsNullPtrErr   Indicates an error when the obj  pointer is null
*/

IPPAPI(IppStatus, ippsDecodeInit_G726_8u16s,
       (IppsDecoderState_G726_16s* pDecMem, IppSpchBitRate rate, IppPCMLaw law))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsDecode_G726
//  Purpose:       Initializes the memory for the ADPCM encode
//  Parameters:
//    pDecMem      Pointer to the decoder state memory
//    pSrc         Pointer to the input ADPCM code vector contains two, three,
//                 four or five bits of the ADPCM codes per byte respectively for
//                 16, 24, 32 or 40 Kbit/s bit rates.
//    pDst         Pointer to the 16bit linear PCM speech output vector.
//    len          The length of input/output vectors.
//  Returns:
//    ippStsNoErr,      if no errors
//    ippStsBadArgErr   Indicates an error when the len is less or equal to 0.
//    IppStsNullPtrErr   Indicates an error when the pDecMem , pSrc, pDst pointer is null
*/
IPPAPI(IppStatus, ippsDecode_G726_8u16s,
       (IppsDecoderState_G726_16s* pDecMem, const Ipp8u *pSrc, Ipp16s *pDst, unsigned int len))
/* /////////////////////////////////////////////////////////////////////////////
//                               G.726 end
///////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////////////////////////////////////////////////
//                         G.728 related functions
///////////////////////////////////////////////////////////////////////////// */
/*
//  Name:        ippsIIR16s_G728
//  Purpose:     IIR filter
//                      1+B(1/z)/1+A(1/z)
//   pCoeffs        pointer to the input filter coefficients B[11], A[11] in Q14
//   pSrcQntSpeech  pointer to the input quantized speech vector
//   pDstWgtSpeech  pointer to the output perceptually weighted speech vector
//   pMem           pointer to the filter memory
*/
#if !defined( _OWN_BLDPCS )

typedef struct _IIRState_G728_16s IppsIIRState_G728_16s;

#endif

IPPAPI(IppStatus, ippsIIR16sGetStateSize_G728_16s, (int *pSize))
IPPAPI(IppStatus, ippsIIR16sInit_G728_16s, (IppsIIRState_G728_16s *pMem ))
IPPAPI(IppStatus, ippsIIR16s_G728_16s, (const Ipp16s *pCoeffs, const Ipp16s *pSrcQntSpeech,
       Ipp16s *pDstWgtSpeech, int len, IppsIIRState_G728_16s *pMem ))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippSynthesisFilter_G728
//  Purpose:    Synthesis filter of size LPC (50)
//                  1/1+A(1/z)
//   pCoeffs       pointer to the input LPC filter coefficients vector[51]
//   pSrcDstExc    pointer to the input/output gain-scaled excitation vector[5] (ET)
//   excSfs        input scale of the previous gain-scaled excitation vector (NLSET)
//   pDstSpeech    pointer to the output quantized speech vector[5] (ST)
//   pSpeechSfs    output scale of the quantized speech vector (NLSST)
//   pMem          pointer to the filter memory
*/

#if !defined( _OWN_BLDPCS )

typedef struct _SynthesisFilterState_G728_16s IppsSynthesisFilterState_G728_16s;

#endif

IPPAPI(IppStatus, ippsSynthesisFilterGetStateSize_G728_16s,(int* pSize))
IPPAPI(IppStatus, ippsSynthesisFilterInit_G728_16s,(IppsSynthesisFilterState_G728_16s *pMem))
IPPAPI(IppStatus, ippsSyntesisFilterZeroInput_G728_16s,(const Ipp16s* pCoeffs,
       Ipp16s *pSrcDstExc, Ipp16s excSfs,Ipp16s *pDstSpeech, Ipp16s *pSpeechSfs,
       IppsSynthesisFilterState_G728_16s *pMem))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsCombinedFilter_G728
//  Purpose:    Combined filter
//              Synthesis filter of size LPC (50) + Perceptual weighted filter (IIR)
//                  1/1+A(1/z) * 1+B(1/z)/1+A(1/z)
//   pSyntCoeffs pointer to the input LPC coefficient vector[51]: 1, a0,...,a50
//   pWgtCoeffs  pointer to the input WGT filter coefficients B[11] 1,b0,...,b10,
                 and A[11] 1,a0,...,a10 in Q14
//   pDstWgtZIR  pointer to the output synthesised speech vector
//   pSrcDstExc  pointer to the input/output gain-scaled excitation vector[5] (ET)
//   excSfs      input scale of the previous gain-scaled excitation vector (NLSET)
//   pDstSpeech  pointer to the output quantized speech vector[5] (ST)
//   pSpeechSfs  output scale of the quantized speech vector (NLSST)
//   pMem       pointer to the filter memory
*/

#if !defined( _OWN_BLDPCS )

typedef struct _CombinedFilterState_G728_16s IppsCombinedFilterState_G728_16s;

#endif

IPPAPI(IppStatus, ippsCombinedFilterGetStateSize_G728_16s,(int* pSize))
IPPAPI(IppStatus, ippsCombinedFilterInit_G728_16s,(IppsCombinedFilterState_G728_16s* pMem))
IPPAPI(IppStatus, ippsCombinedFilterZeroInput_G728_16s,(const Ipp16s* pSyntCoeff,
       const Ipp16s* pWgtCoeff, Ipp16s* pDstWgtZIR, IppsCombinedFilterState_G728_16s* pMem))
IPPAPI(IppStatus, ippsCombinedFilterZeroState_G728_16s,(const Ipp16s* pSyntCoeff,
       const Ipp16s* pWgtCoeff, Ipp16s* pSrcDstExc, Ipp16s excSfs,
       Ipp16s* pDstSpeech, Ipp16s* pSpeechSfs, IppsCombinedFilterState_G728_16s* pMem))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsPostFilter_G728
//  Purpose:    Post filter
//             gl*(1+glb*1/z^kp)* 1-B(1/z)/1-A(1/z) * (1+kp*1/z)
//   gl         LTP scaling factor
//   glb        LTP product term
//   kp         LTP lag, pitch period of current frame
//   tiltz      STP tilt-compensation coefficient
//   pCoeffs    pointer to the input LPC filter coefficients B(10), A(10)
//   pSrc       pointer to the input quantized speech vector SST [-kp,IDIM-1]
//   pDst       pointer to the output postfiltered speech vector
//   pSTPmem    pointer to the filter memory (61 short integers)
*/

#if !defined( _OWN_BLDPCS )

typedef struct _PostFilterState_G728_16s IppsPostFilterState_G728_16s;

#endif

IPPAPI(IppStatus, ippsPostFilterGetStateSize_G728_16s,(int *pSize))
IPPAPI(IppStatus, ippsPostFilterInit_G728_16s,(IppsPostFilterState_G728_16s *pMem))
IPPAPI(IppStatus, ippsPostFilter_G728_16s,(Ipp16s gl, Ipp16s glb, Ipp16s kp, Ipp16s tiltz,
                     const Ipp16s *pCoeffs, const Ipp16s *pSrc,  Ipp16s *pDst,
                     IppsPostFilterState_G728_16s *pMem))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsWinHybrid_G728
//  Purpose:    Hybrid window auto-correlation for backward-adaptive analysis
//              in LD-CELP window:
//                    s(M-N),s(M-N+1),...,s(M-1),s(M),s(M+1),...,s(M+L-1)
//      M       LPC order for backward adaptation
//      L       number of signal samples in backward adaptation
//      N       number of non-recursive samples in the hybrid window
//      DIM     block size, shall be defined for block scaled operation by
//              the function _ippsWinHybridBlock_G728_16s,
//              where pSrcSfs[i] is the scale factor of pSrc[i*DIM],...,pSrc[i*DIM+DIM-1]
//              If 0, then default scale factor 14 is always used.
//      pSrc    input signal for backward-adaptive analysis
//
// ippsWinHybridGetStateSize_G728_16s: return the size of HWM memory
// ippsWinHybridInit_G728_16s: initialized the HWM memory given
// ippsWinHybridBlock_G728_16s : block operation
// ippsWinHybrid_G728_16s : non-block operation
*/
#if !defined( _OWN_BLDPCS )

typedef struct _WinHybridState_G728_16s IppsWinHybridState_G728_16s;

#endif

IPPAPI(IppStatus, ippsWinHybridGetStateSize_G728_16s,(int M, int L, int N, int DIM, int *pMemSize))
IPPAPI(IppStatus, ippsWinHybridInit_G728_16s,(const Ipp16s *pWinTab,int M, int L, int N,
       int DIM, Ipp16s a2L, IppsWinHybridState_G728_16s *pMem))
IPPAPI(IppStatus, ippsWinHybridBlock_G728_16s,(Ipp16s bfi, const Ipp16s *pSrc, const Ipp16s *pSrcSfs, Ipp16s *pDst,
                                       IppsWinHybridState_G728_16s *pMem))
IPPAPI(IppStatus, ippsWinHybrid_G728_16s,(Ipp16s bfi, const Ipp16s *pSrc, Ipp16s *pDst,
                                  IppsWinHybridState_G728_16s *pMem))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsLevinsonDurbin_G728
//  Purpose:    Calculates LPC by Levinson-Durbin recursion
//    pSrcAutoCorr          pointer to the autocorrelation vector
//    numSrcLPC             number of precalculated LPC
//    order                 LP order
//    pDstLPC               pointer to the LPC output vector
//    pSrcDstLPC            pointer to the input/output LPC vector
//    pDstRC1               pointer to the output first RC
//    pDstResidualEnergy    pointer to output residual energy
//    pDstScaleFactor       pointer to the output scale factor of LPC
//    pSrcDstScaleFactor    pointer to the input/output scale factor of LPC
*/
IPPAPI(IppStatus,  ippsLevinsonDurbin_G728_16s_Sfs,(const Ipp16s *pSrcAutoCorr,
                                            int order,
                                            Ipp16s *pDstLPC,
                                            Ipp16s *pDstRC1,
                                            Ipp16s *pDstResidualEnergy,
                                            Ipp16s *pDstScaleFactor))
IPPAPI(IppStatus,  ippsLevinsonDurbin_G728_16s_ISfs,(const Ipp16s *pSrcAutoCorr,
                                            int numSrcLPC,
                                            int order,
                                            Ipp16s *pSrcDstLPC,
                                            Ipp16s *pSrcDstResidualEnergy,
                                            Ipp16s *pSrcDstScaleFactor))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsCodebookSearch_G728
//  Purpose:    Search for the best codebook vector
//    pSrcCorr        pointer to the input correlation vector
//    pSrcEnergy      pointer to the input energy of convolved shape codevector
//    pDstShapeIdx    pointer to the output best 7-bit shape codebook index
//    pDstGainIdx     pointer to the output best 3-bit gain codebook index
//    rate            input coding bit rate :
//                      IPP_SPCHBR_16000, IPP_SPCHBR_12800 or IPP_SPCHBR_9600
*/
IPPAPI(IppStatus, ippsCodebookSearch_G728_16s,(
      const Ipp16s* pSrcCorr, const Ipp16s* pSrcEnergy,
      int* pDstShapeIdx, int* pDstGainIdx, Ipp16s* pDstCodebookIdx, IppSpchBitRate rate))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsImpulseResponseEnergy_G728
//  Purpose:    Shape codevector convolution and energy calculation
//    pSrcImpResp - pointer to the input impulse response vector of F(z)W(z)
//    pDstEnergy - pointer to the output energy of convolved shape codevector Y2[1,NCWD]
*/
IPPAPI(IppStatus, ippsImpulseResponseEnergy_G728_16s,(const Ipp16s *pSrcImpResp, Ipp16s *pDstEnergy))

/* Postfilter adapter block */

#if !defined( _OWN_BLDPCS )

typedef struct _PostFilterAdapterState_G728 IppsPostFilterAdapterState_G728;

#endif

/* /////////////////////////////////////////////////////////////////////////////
// Name:          ippsPostFilterAdapterGetStateSize_G728
// Purpose:       return the size of postfilter adapter memory.
*/
IPPAPI(IppStatus, ippsPostFilterAdapterGetStateSize_G728, (int *pSize))

/* /////////////////////////////////////////////////////////////////////////////
// Name:          ippsPostFilterAdapterStateInit_G728
// Purpose:       initializes the memory for postfilter adapter.
*/
IPPAPI(IppStatus, ippsPostFilterAdapterStateInit_G728, (IppsPostFilterAdapterState_G728 *pMem))

/* /////////////////////////////////////////////////////////////////////////////
// Name:          ippsLPCInverseFilter_G728_16s
//
// Purpose:       compute the LPC prediction residual for the current decoded speech vector. (block 81)
// Parameters:
//    pSrcSpeech        pointer to quantized speech buffer. (sst)
//    pCoeffs           pointer to 10th-order LPC filter coefficients. (apf)
//    pDstResidual      pointer to LPC prediction residual memory. (d)
//    pMem              pointer to postfilter adapter memory. (LPC inverse filter memory - "stlpci")
// Returns:             IppStatus
//    ippStsNoErr       Ok
//    ippStsNullPtrErr  At least one of the specified pointers is NULL
// Notes:
*/
IPPAPI(IppStatus, ippsLPCInverseFilter_G728_16s, (const Ipp16s* pSrcSpeech, const Ipp16s* pCoeffs,
       Ipp16s* pDstResidual, IppsPostFilterAdapterState_G728* pMem))

/* /////////////////////////////////////////////////////////////////////////////
// Name:          ippsPitchPeriodExtraction_G728_16s
//
// Purpose:       extract the pitch period from the LPC prediction residual. (block 82)
// Parameters:
//    pSrcResidual      pointer to LPC prediction residual memory. (d)
//    pPitchPeriod      pointer to the pitch period of the frame. (kp1)
//    pMem              pointer to postfilter adapter memory. (lpfiir, lpfiir, dec)
// Returns:             IppStatus
//    ippStsNoErr       Ok
//    ippStsNullPtrErr  At least one of the specified pointers is NULL
// Notes:
*/
IPPAPI(IppStatus, ippsPitchPeriodExtraction_G728_16s, (const Ipp16s* pSrcResidual,
       int* pPitchPeriod, IppsPostFilterAdapterState_G728* pMem))

/* /////////////////////////////////////////////////////////////////////////////
//                               G.728 end
///////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////////////////////////////////////////////////
//                         GSMFR related functions
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsRPEQuantDecode_GSMFR_16s
//  Purpose:    APCM inverse quantization: decoding the RPE sequence of coded xMc
//    pSrc        pointer to the input RPE pulses vector[13] (xMc)
//    pDst        pointer to the output reconstructed long-term residual vector[13] (xMp)
//    ampl        block amplitude (xmaxc)
//    amplSfs     block amplitude scale factor
*/
IPPAPI(IppStatus, ippsRPEQuantDecode_GSMFR_16s,
       (const Ipp16s *pSrc, Ipp16s ampl, Ipp16s amplSfs, Ipp16s *pDst))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsDeemphasize_GSMFR_16s_I
//  Purpose:    De-emphasis filtering (GSM 06.10 5.3.5)
//    pSrcDst     pointer to the input ST-synthesized signal (sr)
//                and output post-processed speech (sr0)
//    pMem        pointer to the filter memory element
//    len         length of input/output vector
*/
IPPAPI(IppStatus, ippsDeemphasize_GSMFR_16s_I,(Ipp16s *pSrcDst,int len,Ipp16s *pMem))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsShortTermSynthesisFilter_GSMFR_16s
//  Purpose:    Short-term synthesis filtering (GSM 06.10 5.3.2)
//                 1/A(z)
//    pRC         pointer to the input reflection coefficients vector[8]
//    pSrc        pointer to the input reconstructed short term residual vector[len]
//    pDstSpch    pointer to the output speech vector[len]
//    len         length of input residual and output speech vectors
//    pMem        pointer to the filter memory vector[9]
*/
IPPAPI(IppStatus, ippsShortTermSynthesisFilter_GSMFR_16s,
       (const Ipp16s *pRC, const Ipp16s *pSrcResidual, Ipp16s *pDstSpch, int len, Ipp16s *pMem))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsShortTermAnalysisFilter_GSMFR_16s_I
//  Purpose:    Short-term analysys filtering (GSM 06.10 5.2.10)
//                 1/A(z)
//    pRC         pointer to the input reflection coefficients vector[8]
//    pSrcDstSpch pointer to the input preprocessed signal and output
//                short term residual vector[len]
//    len         length of input residual and output speech vectors
//    pMem        pointer to the filter memory vector[9]
*/
IPPAPI(IppStatus, ippsShortTermAnalysisFilter_GSMFR_16s_I,
       (const Ipp16s *pRC, Ipp16s *pSrcDstSpch, int len, Ipp16s *pMem))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsHighPassFilter_GSMFR
//  Purpose:     Offset compensation of the input signal, GSM 06.10 5.2.2
//  Parameters:
//    pSrc        pointer to the input speech vector
//    pDst        pointer to the output filtered vector
//    len         length of input and output vectors
//    pMem        pointer to the filter memory vector[2]
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsHighPassFilter_GSMFR_16s,
       (const Ipp16s *pSrc, Ipp16s *pDst,int len,int *pMem))
/*/////////////////////////////////////////////////////////////////////////////
//  Name:       ippsSchur_GSMFR
//  Purpose:    Calculates reflection coefficients using Schur algorithm. GSM 06.10 5.2.5.
//
//  Arguments:
//     pSrc   - Pointer to the input autocorrelations vector
//     pDst   - Pointer to the output reflection coefficients vector
//     dstLen - vector destination length
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsSchur_GSMFR_32s16s,(const Ipp32s *pSrc,Ipp16s *pDst,int dstLen))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsWeightingFilter_GSMFR
//  Purpose:  weighting filtering.  GSM 06.10 5.2.13
//  Arguments:
//     pSrc      - pointer to the source vector
//     pDst      - pointer to the destination vector
//     dstLen    - source/destination length
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsWeightingFilter_GSMFR_16s,(const Ipp16s *pSrc, Ipp16s *pDst,int dstLen))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsPreemphasize_GSMFR
//  Purpose:     preemphasize offset compensated signal. GSM 06.10 5.2.3
//  Arguments:
//     pSrc      - pointer to the source vector
//     pDst      - pointer to the destination vector
//     pMem      - pointer to the filter memory value
//     len       - source/destination length
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsPreemphasize_GSMFR_16s,
       (const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s *pMem))
/* /////////////////////////////////////////////////////////////////////////////
//                         GSMFR end
///////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////////////////////////////////////////////////
//                         AMRWB related functions
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsResidualFilter_AMRWB_16s_Sfs
//  Purpose:     Compute the LPC residual by filtering the input speech through A(z).
//               rounding to nearest:
//                  const1 = 1<<(scaleFactor-1)
//                  (a*b+const1)>>scaleFactor;
//  Parameters:
//    pSrcLpc               pointer to the input LPC
//    valLPCOrder           length of the LPC vector
//    pSrcSpeech            pointer to the input vector[-valLPCOrder,..,-1,0,...,,len-1]
//    pDstResidualSignal    pointer to the output vector of length[len]
//    len                   length of the vectors
//    scaleFactor           scale factor value
//  Returns:  ippStsNoErr, if no errors
*/

IPPAPI( IppStatus, ippsResidualFilter_AMRWB_16s_Sfs,(
  const Ipp16s *pSrcLpc,
  Ipp16s valLPCOrder,
  const Ipp16s *pSrcSpeech,
  Ipp16s *pDstResidualSignal,
  Ipp32s len,
  Ipp32s scaleFactor
))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsResidualFilter_Low_16s_Sfs
//  Purpose:     Compute the LPC residual by filtering the input speech through A(z).
//               rounding to nearest:
//                  const1 = 1<<(scaleFactor-1)
//                  (a*b+const1)>>scaleFactor;
//  Parameters:
//    pSrcLpc               pointer to the input LPC
//    valLPCOrder           length of the LPC vector
//    pSrcSpeech            pointer to the input vector[-valLPCOrder,..,-1,0,...,,len-1]
//    pDstResidualSignal    pointer to the output vector of length[len]
//    len                   length of the vectors
//    scaleFactor           scale factor value
//  Returns:  ippStsNoErr, if no errors
*/

IPPAPI( IppStatus, ippsResidualFilter_Low_16s_Sfs,(
  const Ipp16s *pSrcLpc,
  Ipp16s valLPCOrder,
  const Ipp16s *pSrcSpeech,
  Ipp16s *pDstResidualSignal,
  Ipp32s len,
  Ipp32s scaleFactor
))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsConvPartial_NR_16s
//  Purpose:    Linear Convolution of 1D signals
//               dst[n] = sum(i=[0,n])(src1[i]*src2[n-i]), n=[0,len-1]
//               Only len results are computed and written to destination vector.
//               rounding to nearest:
//                  const1 = 1<<(scaleFactor-1)
//                  (a*b+const1)>>scaleFactor;
//  Parameters:
//    pSrc1     pointer to the first source vector
//    pSrc2     pointer to the second source vector
//    pDst      pointer to the destination vector
//    len       length of the destination vector
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI(IppStatus, ippsConvPartial_NR_16s,(
     const Ipp16s *pSrc1,
     const Ipp16s *pSrc2,
     Ipp16s *pDst,
     Ipp32s len
))

/* /////////////////////////////////////////////////////////////////////////////
//  Name : ippsLPCToISP_AMRWB_16s
//  Purpose: LP to ISP coefficients conversion
//  Parameters:
//    pSrcLpc      pointer to the input predictor coefficients
//    pDstIsp      pointer to the output immittance spectral pairs
//    pSrcPrevIsp  pointer to the input previouse immittance spectral pairs.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI( IppStatus, ippsLPCToISP_AMRWB_16s,(
     const Ipp16s *pSrcLpc,
     Ipp16s *pDstIsp,
     const Ipp16s *pSrcPrevIsp
))

/* /////////////////////////////////////////////////////////////////////////////
//  Name : ippsISPToLPC_AMRWB_16s
//  Purpose: ISP to LP coefficients conversion
//  Parameters:
//    pSrcIsp      pointer to the input immittance spectral pairs
//    pDstLpc      pointer to the output predictor coefficients
//    len         length of the destination vector.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI( IppStatus, ippsISPToLPC_AMRWB_16s,(
     const Ipp16s *pSrcIsp,
     Ipp16s *pDstLpc,
     Ipp32s len
))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsISPToISF_Norm_AMRWB_16s
//  Purpose:
//               pDstIsf[i] = arccos(pSrcIsp[i]);  i=0,...,lenLpc
//               result is 15 bit scaled in range [0:0.5]
//  Parameters:
//    pSrcIsp       pointer to the ISP input vector of values 15 bit scaled in range [-1:1]
//    pDstIsf       pointer to the ISF output vector
//    len           ISP order
//  Returns:  ippStsNoErr, if no errors
*/

IPPAPI( IppStatus, ippsISPToISF_Norm_AMRWB_16s,(
     const Ipp16s *pSrcIsp,
     Ipp16s *pDstIsf,
     Ipp32s  len
))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsISFToISP_AMRWB_16s
//  Purpose:     ISF interpolation and conversion to LPC
//  Parameters:
//    pSrcIsf       pointer to the ISF input vector of values 15 bit scaled in range [0:0.5]
//    pDstIsp       pointer to the LPC output vector of values 15 bit scaled in range [-1:1]
//    len           ISP order
//  Returns:  ippStsNoErr, if no errors
//
*/

IPPAPI( IppStatus, ippsISFToISP_AMRWB_16s,(
     const Ipp16s *pSrcIsf,
     Ipp16s *pDstIsp,
     Ipp32s  len
))


/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsEncDTXBuffer_AMRWB_16s
//
// Purpose:       Function buffer the ISP coefficients and previous log energy coefficients.
// Parameters:
//  pSrcSpch     - Pointer to the input speech signal, in the length of 320, in Q15.0.
//  pSrcLsp      - Pointer to the ISP for this frame, in the length of 16, in Q0.15.
//  pUpdateIndex - Pointer to the previous memory update index. It is a value
//                 circularly increased between 0 and 7.
//  pSrcDstLspBuffer - Pointer to the ISP coefficients of eight previous frames, in the
//                 length of 128, in Q0.15.
//  pSrcDstLogEnergyBuffer - Pointer to the logarithm energy coefficients of eight previous
//                 frames,in the length of 8,in Q5.10.
//  mode         - coder mode
// Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI(IppStatus, ippsEncDTXBuffer_AMRWB_16s,(const Ipp16s * pSrcSpch,
                  const Ipp16s *pSrcIsp, Ipp16s *pUpdateIndex, Ipp16s *pSrcDstIspBuffer,
                  Ipp16s *pSrcDstLogEnergyBuffer, IppSpchBitRate mode))

/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsDecDTXBuffer_AMRWB_16s
//
// Purpose:       Function buffer the ISF coefficients and previous log energy coefficients.
// Parameters:
//  pSrcSpch     - Pointer to the input speech signal, in the length of 320, in Q15.0.
//  pSrcIsf      - Pointer to the ISF for this frame, in the length of 16, in Q0.15.
//  pUpdateIndex - Pointer to the previous memory update index. It is a value
//                 circularly increased between 0 and 7.
//  pSrcDstIsfBuffer - Pointer to the ISF coefficients of eight previous frames, in the
//                 length of 128, in Q0.15.
//  pSrcDstLogEnergyBuffer - Pointer to the logarithm energy coefficients of eight previous
//                 frames,inthelength of 8,in Q5.10.
// Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI( IppStatus, ippsDecDTXBuffer_AMRWB_16s,(const Ipp16s *pSrcSpch,
                  const Ipp16s *pSrcIsf, Ipp16s *pUpdateIndex,
                  Ipp16s *pSrcDstIsfBuffer, Ipp16s *pSrcDstLogEnergyBuffer))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsOpenLoopPitchSearch_AMRWB_16s
//
//  Purpose:   Extracts an open-loop pitch lag estimate from the weighted input speech
//  Parameters:
//   pSrcWgtSpch                  Pointer to a 320-element vector containing
//                                perceptually weighted speech.
//   pSrcFltWgtSpch               Pointer to a 320-element vector containing filtered
//                                perceptually weighted speech.
//   pPrevMidPitchLag             Pointer to the median filtered pitch lag
//                                of the 5 previous voiced
//                                speech half-frames
//   pAdaptiveParam               Pointer to the adaptive parameter v
//   pDstOpenLoopLag              Pointer to a two-element vector of open-loop pitch lags.
//   pToneFlag                    Pointer to the tone flag for the VAD module.
//   pDstOpenLoopGain             Pointer to a 2-element vector containing
//                                optimal open-loop pitch gains.
//   pSrcDstPrevPitchLag          Pointer to the five-element vector that contains
//                                the pitch lags associated
//                                with the five most recent voiced speech half-frames
//   pSrcDstLagSwitcher           Switches lag weighting on and off
//   mode                         coder mode
//  Returns:                    IppStatus
//      ippStsNoErr             if no error
*/

IPPAPI( IppStatus, ippsOpenLoopPitchSearch_AMRWB_16s,(const Ipp16s *pSrcWgtSpch,
      const Ipp16s * pSrcFltWgtSpch, Ipp16s * pPrevMidPitchLag,
      Ipp16s * pAdaptiveParam, Ipp16s * pDstOpenLoopLag,
      Ipp16s * pToneFlag, Ipp16s * pDstOpenLoopGain,
      Ipp16s * pSrcDstPrevPitchLag, Ipp16s * pSrcDstLagSwitcher, int len ))

#if !defined( _OWN_BLDPCS )

typedef struct _HighPassFilterState_AMRWB_16s IppsHighPassFilterState_AMRWB_16s;

#endif /* _OWN_BLDPCS */

/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsHighPassFilterGetSize_AMRWB_16s
//  Purpose:     Query of AMRWB HP filter state memory size

//  Parameters:
//    pDstSize      Pointer to the output value of the memory size needed for filtering
//    order         Order of filter/ Currently only 2 or 3 is supported
//  Returns:  ippStsNoErr, if no errors
*/

IPPAPI(IppStatus, ippsHighPassFilterGetSize_AMRWB_16s,(int order, int *pDstSize))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsHighPassFilterInit_AMRWB_16s
//  Purpose:     Initialization of the memory allocated for AMR WB high pass filter
//  Parameters:
//    pFilterCoeffA      Pointer to a 4-element vector containing
//                       IIR part of the coefficiensts of the filter
//    pFilterCoeffB      Pointer to a 4-element vector containing
//                       FIR part of the coefficiensts of the filter
//    pState             pointer to the memory supplied for filtering
//  Returns:  ippStsNoErr, if no errors
//
*/

IPPAPI(IppStatus, ippsHighPassFilterInit_AMRWB_16s,
       (Ipp16s *pFilterCoeffA, Ipp16s *pFilterCoeffB, int order,
        IppsHighPassFilterState_AMRWB_16s *pState))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsHighPassFilter_AMRWB
//  Purpose:     High-pass filtering
//  Parameters:
//    pSrc          pointer to the input vector[len]
//    pDst          pointer to the vector [len].
//    pSrcDst       pointer to the input/output vector [len].
//    len           lenght of the input and output vectors.
//    pState        pointer to the memory supplied for filtering
//    valBounds     if valBounds = 0 then pSrc[-1] and pSrc[len] are equal to zero
//                  otherwise they must be given.
//    scaleFactor   Scale factor
//  Returns:  ippStsNoErr, if no errors
*/

IPPAPI(IppStatus, ippsHighPassFilter_AMRWB_16s_Sfs,(
     const Ipp16s *pSrc, Ipp16s *pDst, int len,
     IppsHighPassFilterState_AMRWB_16s *pState, int scaleFactor))

IPPAPI(IppStatus, ippsHighPassFilter_AMRWB_16s_ISfs,(
     Ipp16s *pSrcDst, int len,
     IppsHighPassFilterState_AMRWB_16s *pState, int scaleFactor))

IPPAPI(IppStatus, ippsHighPassFilter_Direct_AMRWB_16s,(
     const Ipp16s *pSrcCoeff, const Ipp16s *pSrc,  Ipp16s *pDst,  int len, int valBounds ))
/* /////////////////////////////////////////////////////////////////////////////
//        AMRWB Voice Activity Detector functions
// /////////////////////////////////////////////////////////////////////////////
*/

#if !defined( _OWN_BLDPCS )

typedef struct _VADState_AMRWB_16s IppsVADState_AMRWB_16s;

#endif /* _OWN_BLDPCS */

/* /////////////////////////////////////////////////////////////////////////////
//  Name: ippsVADGetSize_AMRWB_16s
//  Purpose:    AMRWB VADetector size -
//              computes the size,in bytes,
//              of the state variable structure IppsVADState_AMRWB_16s.
//  Parameters:
//   pState                 pointer to the VAD history variables
//  Returns:                IppStatus
//      ippStsNoErr         if no error
*/
IPPAPI( IppStatus, ippsVADGetSize_AMRWB_16s,(int *pDstSize ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name: ippsVADGetSize_AMRWB_16s
//  Purpose:   Initialize AMRWB VADetector -
//              of the state variable structure IppsVADState_AMRWB_16s.
//  Parameters:
//   pState                 pointer to the VAD history variables
//  Returns:                IppStatus
//      ippStsNoErr         if no error
*/
IPPAPI( IppStatus, ippsVADInit_AMRWB_16s,(
     IppsVADState_AMRWB_16s *pState
))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsVAD_AMRWB_16s
//
//  Purpose:   AMRWB VADetector -
//             detect type of frame - active (voice) or inactive (unvoiced)
//  Parameters:
//   pSrcSpch         pointer to the input speech signal, in the length of 320
//   pState           pointer to the VAD history variables
//   pVadFlag         pointer to the VAD type detected (1 - voice)
//   pToneFlag        pointer to tone detected
//  Returns:          IppStatus
//      ippStsNoErr   if no error
*/

IPPAPI( IppStatus, ippsVAD_AMRWB_16s,(const Ipp16s *pSrcSpch,
                  IppsVADState_AMRWB_16s *pState,
                  Ipp16s *pToneFlag,
                  Ipp16s *pVadFlag))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsAlgebraicCodebookSearch_AMRWB_16s
//
//  Purpose:   Fixed (algebraic) codebook search functions
//  Parameters:
//   pSrcFixedTarget        target vector
//   pSrcLtpResidual        long term prediction residual
//   pSrcDstImpulseResponse impulse response of weighted synthesis
//                          filter h[-L_subfr..-1] must be set to zero
//   pDstFixedVector        innovative codebook
//   pDstFltFixedVector     filtered fixed codebook excitation
//   pDstIndex              Indexes of the pulses
//   mode                   coder mode
//  Returns:                IppStatus
//      ippStsNoErr         if no error
*/

IPPAPI(IppStatus, ippsAlgebraicCodebookSearch_AMRWB_16s,(
     const Ipp16s *pSrcFixedTarget,
     const Ipp16s *pSrcLtpResidual,
     Ipp16s *pSrcDstImpulseResponse,
     Ipp16s *pDstFixedVector,
     Ipp16s *pDstFltFixedVector,
     IppSpchBitRate mode,
     Ipp16s *pDstIndex
))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsAlgebraicCodebookDecode_AMRWB_16s
//
//  Purpose:   This function decodes the fixed (algebraic) codebook parameters transmitted by the encoder.
//  Parameters:
//   pSrcIdxs          Algebraic codebook indexes.
//   pDstFixedCode     Pointer to the algebraic codevector, in the length of 64
//   mode              coder mode
//  Returns:           IppStatus
//      ippStsNoErr    if no error
*/

IPPAPI(IppStatus, ippsAlgebraicCodebookDecode_AMRWB_16s,(
     const Ipp16s *pSrcIdxs,
     Ipp16s *pDstFixedCode,
     IppSpchBitRate mode
))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsInterpolateC_NR_16s
//  Purpose:     interpolation of two vector
//               dst = (src1*va1*2^scaleFactor1 + src2*val2*2^scaleFactor2)*2^-16
//  Parameters:
//    pSrc1           pointer to the input vector1
//    val1            interpolation coeff. of first vector
//    val1ScaleFactor val1 scaling factor
//    pSrc2           pointer to the input vector2
//    val2            interpolation coeff. of second vector
//    val2scaleFactor val2 scaling factor
//    pDst            pointer to the interpolated output vector
//    len             length of the vectors
/  Returns:  ippStsNoErr, if no errors
*/

IPPAPI(IppStatus, ippsInterpolateC_NR_16s,
       (const Ipp16s *pSrc1, Ipp16s val1, int val1ScaleFactor, const Ipp16s *pSrc2,
       Ipp16s val2, int val2ScaleFactor, Ipp16s *pDst, int len))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsPreemphasize_AMRWB_16s_ISfs
//  Purpose:    Preemphasis filter
//               H(z) =  1 - gamma z^-1
//  Parameters:
//    pSrcDst        pointer to the input/output vector
//    gamma          filter coeeficient
//    ScaleFactor    scale factor for the result
//    len            lenght of the input/output vector
//    pMem           pointer to the filter memory of length 1
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI(IppStatus, ippsPreemphasize_AMRWB_16s_ISfs,(Ipp16s gamma, Ipp16s *pSrcDst,
                                             int len, int ScaleFactor, Ipp16s* pMem))

/* /////////////////////////////////////////////////////////////////////////////
//  Name : ippsAdaptiveCodebookGainCoeff_AMRWB_16s
//  Purpose: Compute the adaptive codebook gain
//
//  Parameters:
//   pSrcAdptTarget:       Pointer to the adaptive-codebook vector.
//   pSrcFltAdptVector:    Pointer to the input filtered adaptive-codebook vector.
//   pResultAdptGain:      Pointer to the adaptive-codebook gain in the length of 1.
//   pResultAdptGainCoeffs Pointer to the output vector in the length 4 represents
//                         the adaptive-codebook gain as a fraction:
//                                    xy * 2^exp_xy
//                            gain =  -------------
//                                    yy * 2^exp_yy
//                         where     yy = pResultAdptGainCoeffs[0]
//                               exp_yy = pResultAdptGainCoeffs[1]
//                                   xy = pResultAdptGainCoeffs[2]
//                               exp_xy = pResultAdptGainCoeffs[3]
//                         If xy < 0 then pResultAdptGain = 0;
//   len                   length of vectors
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI( IppStatus, ippsAdaptiveCodebookGainCoeff_AMRWB_16s,(const Ipp16s * pSrcAdptTarget,
       const Ipp16s * pSrcFltAdptVector, Ipp16s * pDstGainCoeff, Ipp16s * pResultAdptGain, int len))

/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsISFQuant_AMRWB_16s
//
// Purpose:       Quantizes the ISF coefficient vector, then obtains quantized ISF codebook indices.
// Parameters:
//  pSrcIsf       - Pointer to the unquantized 16-element ISF vector.
//  pSrcDstResidual  - Pointer to the 16-element quantized ISF residual from the previous
//                 frame.
//  pDstQIsf      - Pointer to the 16-element quantized ISF vector.
//  pDstQIsfIndex - Pointer to the 7-element vector of quantized ISP indices. For 6.60 Kbps
//                 frames only the first five elements contain valid indices,
//                 for all other bit rates, all seven elements contain valid data
// mode          - Bit rate specifier.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI( IppStatus, ippsISFQuant_AMRWB_16s,(const Ipp16s *pSrcIsf,
                  Ipp16s *pSrcDstResidual, Ipp16s *pDstQIsf,
                  Ipp16s *pDstQIsfIndex, IppSpchBitRate mode))

/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsISFQuantDecode_AMRWB_16s
//
// Purpose:       Decodes quantized ISFs from the received codebook index if the
//                 errors are not detected on the received frame. Otherwise, the
//                 function recovers the quantized ISFs from previous quantized
//                 ISFs using linear interpolation.
// Parameters:
// pSrcIdxs                  - Pointer to the seven-element vector containing codebook indices
//                             of the quantized LSPs.
// pSrcDstResidual           - Pointer to the 16-element quantized ISF residual from
//                             the previous frame.
// pSrcPrevQntIsf            - Pointer to the 16-element quantized ISF vector from the previous
//                             frame.
// pSrcDstIsfMemory          - Pointer to the 64-element vector containing four subframe ISF sets.
// pDstQntIsf                - Pointer to a 16-element destination vector containing quantized ISF in frequency domain (0..0.5).
// bfi                       - Bad frame indicator; "0" signifies a good frame; all other values
//                             signify a bad frame.
// mode                      - Bit rate specifier.
// Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI( IppStatus, ippsISFQuantDecode_AMRWB_16s,(
     const Ipp16s *pSrcIdxs,
     Ipp16s *pDstQntIsf,
     Ipp16s *pSrcDstResidual,
     const Ipp16s *pSrcPrevQntIsf,
     Ipp16s *pSrcDstIsfMemory,
     int bfi,
     IppSpchBitRate mode
))

/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsISFQuantDTX_AMRWB_16s
//
// Purpose:       Quantizes the ISP coefficient vector, then obtains quantized ISP codebook indices in case of DTX mode.
// Parameters:
//  pSrcIsf      - Pointer to the unquantized 16-element ISF in the frequency domain (0..0.5) vector.
//  pDstQntIsf   - Pointer to the 16-element quantized ISF vector.
//  pDstIdxs     - Pointer to the 5-element vector quantization indices.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI( IppStatus, ippsISFQuantDTX_AMRWB_16s,(
     const Ipp16s *pSrcIsf,
     Ipp16s *pDstQntIsf,
     Ipp16s *pDstIdxs
))

/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsISFQuantDecodeDTX_AMRWB_16s
//
// Purpose:       Decodes quantized ISFs from the received codebook index in case of DTX mode.
// Parameters:
//  pSrcIdxs     - Pointer to the 5-element vector quantization indices.
//  pDstQntIsf   - Pointer to the 16-element ISF in the frequency domain (0..0.5) vector.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI( IppStatus, ippsISFQuantDecodeDTX_AMRWB_16s,(
     const Ipp16s *pSrcIdxs,
     Ipp16s *pDstQntIsf
))

/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsSynthesisFilter_AMRWB_16s32s_I
//
// Purpose:
// Parameters:
//  pSrcLpc        Pointer to the LP coefficients vector.
//  order          Order of LP filter.
//  pSrcExc        Pointer to the excitation vector.
//  pSrcDst        Pointer to the synthesized and updated speech.
//  len
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI(IppStatus, ippsSynthesisFilter_AMRWB_16s32s_I,(
     const Ipp16s *pSrcLpc, int order,  const Ipp16s *pSrcExc, Ipp32s *pSrcDstSignal, int len))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsDeemphasize_AMRWB
//  Purpose:    De-emphasis filtering.
//  Parameters:
//    gamma      deemphasis factor.
//    pSrc       pointer to the input vector
//    pDst       pointer to the output vector
//    pSrcDst    pointer to the input/output vector
//    pMem       memory (pSrcDst[-1])
//    len        length of input/output vector
*/
IPPAPI(IppStatus, ippsDeemphasize_AMRWB_32s16s,(
     Ipp16s gamma, const Ipp32s *pSrc, Ipp16s *pDst, int len, Ipp16s *pMem))

IPPAPI(IppStatus, ippsDeemphasize_AMRWB_NR_16s_I,(
     Ipp16s gamma, Ipp16s *pSrcDst, int len, Ipp16s *pMem))

/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsAdaptiveCodebookSearch_AMRWB_16s
//
// Purpose:   Performs the adaptive codebook search.
// Parameters:
//   pSrcAdptTarget                  Pointer to the 64-element adaptive target signal vector,
//   pSrcImpulseResponse             Pointer to the 64-element impulse response of the weighted synthesis
//                                    filter.
//   pSrcOpenLoopLag                 Pointer to a two-element vector of open-loop pitch lags.
//   pPitchLag                       Pointer to output the previous integral pitch lag.
//   pPitchLagBounds                 Pointer to output the previous integral pitch lag bounds.
//   pSrcDstExcitation               Pointer to the 321-element excitation vector.
//   pFracPitchLag                   Pointer to output the fractional pitch lag obtained during the adaptive codebook
//                                    search.
//   pAdptIndex                      Pointer to output the coded closed-loop pitch index.
//   subFrame                        Subframe number
//   mode                            Coder mode
// Returns:                    IppStatus
//      ippStsNoErr             if no error
*/

IPPAPI(IppStatus, ippsAdaptiveCodebookSearch_AMRWB_16s,(
      const Ipp16s * pSrcAdptTarget,
      const Ipp16s * pSrcImpulseResponse,
      const Ipp16s * pSrcOpenLoopLag,
      Ipp16s * pPitchLag,
      Ipp16s * pPitchLagBounds,
      Ipp16s * pSrcDstExcitation,
      Ipp16s * pFracPitchLag,
      Ipp16s * pAdptIndex,
      int   subFrame,
      IppSpchBitRate mode))

#if !defined( _OWN_BLDPCS )

typedef struct _AdaptiveCodebookDecodeState_AMRWB_16s IppsAdaptiveCodebookDecodeState_AMRWB_16s;

#endif /* _OWN_BLDPCS */

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsAdaptiveCodebookDecode
//
//   Purpose:   This function decodes the adaptive codebook parameters transmitted by the encoder, and then
//                applies them to interpolate an adaptive codebook vector.
//   valAdptIndex                 Adaptive codebook index.
//   pFracPitchLag          Pointer to the fractional pitch lag obtained during the adaptive codebook
//                                  search.
//   pResultPrevIntPitchLagBounds Pointer to the previous integral pitch lag bounds.
//   pSrcDstExcitation            Pointer to the 321-element excitation vector.
//   pResultIntPitchLag           Pointer to the integral pitch lag.
//   subFrame                     Subframe number
//   bfi                          Bad frame indicator. "0" signifies a good frame; any other value signifies a bad frame.
//   unusableFrame
//   mode                         Coder mode
//   pState                       Pointer to the memory supplied for function.
//  Returns:                    IppStatus
//      ippStsNoErr             if no error
*/

IPPAPI(IppStatus, ippsAdaptiveCodebookDecodeGetSize_AMRWB_16s,(int *pDstSize))

IPPAPI(IppStatus, ippsAdaptiveCodebookDecodeInit_AMRWB_16s,(IppsAdaptiveCodebookDecodeState_AMRWB_16s *pState))

IPPAPI(IppStatus, ippsAdaptiveCodebookDecodeUpdate_AMRWB_16s,(int valIntPitchLag, int valPitchGain,
                                                      IppsAdaptiveCodebookDecodeState_AMRWB_16s *pState))
IPPAPI(IppStatus, ippsAdaptiveCodebookDecode_AMRWB_16s,(
      int valAdptIndex,
      Ipp16s * pFracPitchLag,
      Ipp16s * pSrcDstExcitation,
      Ipp16s * pResultIntPitchLag,
      Ipp16s * pResultPrevIntPitchLagBounds,
      int subFrame,
      int bfi,
      int unusableFrame,
      IppSpchBitRate mode,
      IppsAdaptiveCodebookDecodeState_AMRWB_16s *pState))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsGainQuant_AMRWB_16s
//  Purpose:    Quantization of the adaptive codebook gains
//    pSrcAdptTarget      - pointer to the input target vector x(n).
//    pSrcFltAdptVector   - pointer to the input filterd adaptive codebook vector y(n)
//    valFormat           - format of the  pSrcAdptTarget and pSrcFltAdptVector vectors.
//    pSrcFixedVector     - pointer to the input pre-filtered codebook contribition c(n)
//    pSrcFltFixedVector  - pointer to the input filtered codebook vector z(n)
//    pSrcCorr            - pointer to the vector of correlations between pSrcAdptTarget, pSrcFltAdptVector,
//                          pSrcFltFixedVector vectors.
//    pSrcDstEnergyErr    - pointer to the input/output energy error vector
//                           for 4 previous subframes
//    pSrcDstPitchGain    - Pointer to the input/output pitch gain.
//    pDstCodeGain        - Pointer to the output code gain.
//    valClipFlag         - if valClipFlag = 1 then limit gain pitch to 1.0.
//    pDstQGainIndex      - Pointer to the output codebook indexes found
//    lenSrc              - Lenght of the input vectors.
//    mode                - Coder mode.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI( IppStatus, ippsGainQuant_AMRWB_16s,(
       const Ipp16s *pSrcAdptTarget, const Ipp16s *pSrcFltAdptVector, int valFormat,
       const Ipp16s * pSrcFixedVector, const Ipp16s *pSrcFltFixedVector, const Ipp16s *pSrcCorr,
       Ipp16s *pSrcDstEnergyErr, Ipp16s *pSrcDstPitchGain, int *pDstCodeGain,
       int valClipFlag, Ipp16s *pDstQGainIndex, int lenSrc, IppSpchBitRate mode))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsDecodeGain_AMRWB_16s
//  Purpose:    Decode adaptive and fixed-codebook gains
//    valQIndex           - index of quantization.
//    valEnergy           - energy of code vector.
//    pDstPitchGain       - Pointer to decoded pitch gain.
//    pDstCodeGain        - Pointer to decoded code gain.
//    bfi                 - Bad frame indicator.
//    prevBfi             - Bad frame indicator of the previouse frame.
//    pSrcDstPastEnergy   - past quantized energies
//    pPrevCodeGain       - Past code gain.
//    pSrcDstPastCodeGain - Past code gain for frame erasures.
//    mode                - Coder mode.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/

IPPAPI( IppStatus, ippsDecodeGain_AMRWB_16s,(
     int valQIndex,
     Ipp32s valEnergy,
     Ipp16s *pDstPitchGain,
     int *pDstCodeGain,
     int bfi,
     int prevBfi,
     Ipp16s *pSrcDstPastEnergy,
     Ipp16s *pPrevCodeGain,
     Ipp16s *pSrcDstPastCodeGain,
     IppSpchBitRate mode
))

/* /////////////////////////////////////////////////////////////////////////////
//                         AMRWB end
///////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////////////////////////////////////////////////
//                         G722 SBADPCM related functions
///////////////////////////////////////////////////////////////////////////// */
#if !defined( _OWN_BLDPCS )

  struct EncoderState_G722_16s;
  typedef struct EncoderState_G722_16s IppsEncoderState_G722_16s;

  struct DecoderState_G722_16s;
  typedef struct DecoderState_G722_16s  IppsDecoderState_G722_16s;

#endif /* _OWN_BLDPCS */

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsSBADPCMEncodeStateSize_G722_16s
//  Purpose:    Returns the G722 SBADPCM encoder state memory size
//    pEncMemSize         - pointer to the output encider state memory size in bytes.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI (IppStatus, ippsSBADPCMEncodeStateSize_G722_16s, (int* pEncMemSize))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsSBADPCMEncodeInit_G722_16s
//  Purpose:    This function initializes the memory buffer referenced by the pointer pEncMem.
//    pEncMem      - pointer to the input memory buffer of size required to properly initialize the encoder.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI (IppStatus, ippsSBADPCMEncodeInit_G722_16s, (IppsEncoderState_G722_16s* pEncMem))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsSBADPCMEncode_G722_16s
//  Purpose:    Encode lower and upper sub-band of incoming speech or music.
//    pSrc      - pointer to the input vector of synthesis QMF samples.
//    pDst      - pointer to the ADPCM bit-stream output vector.
//    len       - the length of input vector, must be a multiple of two.
//    pEncMem   - pointer to the state memory of the Sub-Band ADPCM encoder.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI (IppStatus, ippsSBADPCMEncode_G722_16s, (const Ipp16s *pSrc, Ipp16s *pDst,
        int len, IppsEncoderState_G722_16s* pEncMem))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsQMFEncode_G722_16s
//  Purpose:    This function uses Quadrature Mirror Filtering (QMF) of the 14-bit
//              uniform PCM speech input to compute the lower and higher sub-band signal
//              components for the Sub-Band ADPCM encoder.
//    pSrc      - pointer to the uniform PCM input speech vector.
//    pDst      - pointer to the synthesis QMF samples output vector.
//    len       - the length of input/output vectors, must be a multiple of two.
//    delay     - pointer to the buffer of a delay line.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI (IppStatus, ippsQMFEncode_G722_16s,
        (const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s *delay))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsSBADPCMDecodeStateSize_G722_16s
//  Purpose:    Returns the G722 SBADPCM decoder state memory size
//    pDecMemSize   - pointer to the output decoder state memory size in bytes.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI (IppStatus, ippsSBADPCMDecodeStateSize_G722_16s, (int* pDecMemSize))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsSBADPCMDecodeInit_G722_16s
//  Purpose:    Initializes the memory buffer referenced by the pointer pDecMem.
//    pDecMem      - Pointer to the input decoder state memory buffer
//                   of size required to properly initialize the decoder.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI (IppStatus, ippsSBADPCMDecodeInit_G722_16s, (IppsDecoderState_G722_16s *pDecMem))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsSBADPCMDecode_G722_16s
//  Purpose:    Decode lower sub-band of input audio signal.
//    pSrc      - pointer to the input vector that contains unpacked
//                lower and high ADPCM 16bit samples given in pair.
//    pDst      - Pointer to the output vector that contains decoded low-
//                and high- bands portions of the recovered audio samples.
//    len       - the length of the input vector, must be multiple of two.
//    mode      - decode bit rate of the G.722 decoder.
//    pDecMem   - pointer to the state memory of the Sub-Band ADPCM decoder.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI (IppStatus, ippsSBADPCMDecode_G722_16s, (const Ipp16s *pSrc, Ipp16s *pDst,
        int len, Ipp16s mode, IppsDecoderState_G722_16s * pDecMem))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsQMFDecode_G722_16s
//  Purpose:    This function performs Quadrature Mirror Filter (QMF) synthesis
//              of the low- and high- bands portions of the recovered samples
//              to reconstruct the output signal.
//    pSrc      - pointer to the input vector that contains decoded low- and high- bands
//                portions of the recovered samples.
//    pDst      - pointer to the output vector of 16bit linear PCM audio samples.
//    len       - the length of input/output vectors, must be a multiple of two.
//    delay     - pointer to the buffer of a delay line.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI (IppStatus, ippsQMFDecode_G722_16s,
        (const Ipp16s *pSrc, Ipp16s *pDst, int len, Ipp16s *delay))
/* /////////////////////////////////////////////////////////////////////////////
//                         G722 SBADPCM end
///////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////////////////////////////////////////////////
//                         Echo Canceller related functions
///////////////////////////////////////////////////////////////////////////// */

#if !defined( _OWN_BLDPCS )
  struct _SubbandProcessState_32f;
  typedef struct _SubbandProcessState_32f IppsSubbandProcessState_32f;
  struct _SubbandControllerState_EC_32f;
  typedef struct _SubbandControllerState_EC_32f IppsSubbandControllerState_EC_32f;
  struct _FullbandControllerState_EC_32f;
  typedef struct _FullbandControllerState_EC_32f IppsFullbandControllerState_EC_32f;
  struct _ToneDetectState_EC_32f;
  typedef struct _ToneDetectState_EC_32f IppsToneDetectState_EC_32f;

  struct _SubbandProcessState_16s;
  typedef struct _SubbandProcessState_16s IppsSubbandProcessState_16s;
  struct _SubbandControllerState_EC_16s;
  typedef struct _SubbandControllerState_EC_16s IppsSubbandControllerState_EC_16s;
  struct _FullbandControllerState_EC_16s;
  typedef struct _FullbandControllerState_EC_16s IppsFullbandControllerState_EC_16s;
  struct _ToneDetectState_EC_16s;
  typedef struct _ToneDetectState_EC_16s IppsToneDetectState_EC_16s;
#endif /* _OWN_BLDPCS */

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsSubbandProcessGetSize
//
//  Purpose:
//    Returns size of the state structure
//
//  Parameters:
//    order                 Number of subbands = (2 ^ (order � 1) + 1)
//    windowLen             Length of window
//    pStateSize            Pointer to the computed value of size of buffer
//                          for state structure.
//    pInitBufSize          Pointer to the computed size of buffer for use
//                          in initialization function
//    pBufSize              Pointer to the computed size of work buffer.
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when pSize is NULL.
//    ippStsBadArgErr       Indicates an error when order is less than or
//                          equal to 0 or windowLen is not divisibly by 2 ^
//                          order
*/

IPPAPI(IppStatus, ippsSubbandProcessGetSize_32f, (int order, int windowLen,
      int *pSize, int *pInitBufSize, int *pBufSize))
IPPAPI(IppStatus, ippsSubbandProcessGetSize_16s, (int order, int windowLen,
      int *pSize, int *pInitBufSize, int *pBufSize))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsSubbandProcessInit
//
//  Purpose:
//    Initializes the state structure
//
//  Parameters:
//    pState                Pointer to the state structure to be created
//    order                 Number of subbands = (2 ^ (order � 1) + 1)
//    frameSize             Size of frame. Should be in range [1, 2 ^order]
//    windowLen             Window length
//    pWindow               Pointer to window coefficients (may be NULL, if
//                          the order, frameSize and windowLen are equal to
//                          one of the predefined values: (5, 24, 128) or
//                          (6, 44, 256). In this case the predefined
//                          window is used.
//    pInitBuf              Pointer to the init buffer
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when buf or pState is NULL.
//    ippStsBadArgErr       Indicates an error when order is less or equal
//                          to 0 or windowLen is not divisibly by 2 ^ order
//                          or frameSize is less than or equal to 0 or (
//                          window is NULL and appropriate internal window
//                          doesn't exist).
*/

IPPAPI(IppStatus, ippsSubbandProcessInit_32f, (
      IppsSubbandProcessState_32f *state,
      int order, int frameSize, int windowLen, const Ipp32f *pWindow,
      Ipp8u *pInitBuf))
IPPAPI(IppStatus, ippsSubbandProcessInit_16s, (
      IppsSubbandProcessState_16s *state,
      int order, int frameSize, int windowLen, const Ipp16s *pWindow,
      Ipp8u *pInitBuf))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsSubbandAnalysis
//
//  Purpose:
//    Decomposes frame into complex subband representation
//
//  Parameters:
//    pSignal               Pointer to the source vector of the length equal
//                          to the frame size which was used to initialize
//                          the subband process algorithm by
//                          ippsSubbandProcessInit function.
//    pSubbands             Pointer to the subband results vector of the
//                          length equal to number of subbands, calculated
//                          as (2 ^ (order � 1) + 1), where order is
//                          specified in ippsSubbandProcessInit.
//    pState                Pointer to the state stucture
//    pBuf                  Pointer to work buffer, user to allocate of size
//                          specified by the parameter pBufSise
//                          ippsSubbandProcessGetSize function.
//    scalefactor           scale factor value
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when one of the specified
//                          pointers is NULL.
*/

IPPAPI(IppStatus, ippsSubbandAnalysis_32f32fc, (const Ipp32f *pSignal, Ipp32fc *pSubbands,
      IppsSubbandProcessState_32f *pState, Ipp8u *pBuf))
IPPAPI(IppStatus, ippsSubbandAnalysis_16s32sc_Sfs, (const Ipp16s *pSignal, Ipp32sc *pSubbands,
      IppsSubbandProcessState_16s *pState, int scalefactor, Ipp8u *pBuf))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsSubbandSynthesis
//
//  Purpose:
//    Reconstructs frame from complex subband representation
//
//  Parameters:
//    pSubbands             Pointer to the subband results vector of the
//                          length equal to number of subbands, calculated
//                          as (2 ^ (order � 1) + 1), where an order is
//                          specified in ippsSubbandProcessInit
//    pSignal               Pointer to the destination signal vector of the
//                          length equal to frame size which was used to
//                          initialize the subband process algorithm by
//                          ippsSubbandProcessInit function.
//    pState                Pointer to the state stucture
//    pBuf                  Pointer to the work buffer of size after the
//                          ippsSubbandProcessGetSize function call (to be
//                          returned via pBufSize parameter)
//    scalefactor           scale factor value
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when one of the specified
//                          pointers is NULL.
*/

IPPAPI(IppStatus, ippsSubbandSynthesis_32fc32f, (const Ipp32fc *pSubbands, Ipp32f *pSignal,
      IppsSubbandProcessState_32f *pState, Ipp8u *pBuf))
IPPAPI(IppStatus, ippsSubbandSynthesis_32sc16s_Sfs, (const Ipp32sc *pSubbands, Ipp16s *pSignal,
      IppsSubbandProcessState_16s *pState, int scalefactor, Ipp8u *pBuf))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsSubbandControllerGetSize_EC
//
//  Purpose:
//    Returns size of the state structure
//
//  Parameters:
//    numSubbands           Number of subbands
//    frameSize             Size of frame
//    numSegments           Number of segments
//    sampleFreq            Sample frequency
//    pSize                 Pointer to the computed buffer size value.
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when pSize NULL.
//    ippStsRangeErr        Indicates an error when sampleFreq is not a valid element
//                          of the enumerated type IppPCMFrequency.
//    ippStsBadArgErr       Indicates an error when numSubbands is less or
//                          equal to 0 or numSegment is less than or equal
//                          to 0 or frameSize is less than or equal to 0.
*/

IPPAPI(IppStatus, ippsSubbandControllerGetSize_EC_32f, (int numSubbands, int frameSize,
      int numSegments, IppPCMFrequency sampleFreq, int *pSize))
IPPAPI(IppStatus, ippsSubbandControllerGetSize_EC_16s, (int numSubbands, int frameSize,
      int numSegments, IppPCMFrequency sampleFreq, int *pSize))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsSubbandControllerInit_EC
//
//  Purpose:
//    Initializes the state structure
//
//  Parameters:
//    pState                Pointer to the state structure to be created
//    numSubbands           Number of subbands
//    frameSize             Size of frame
//    numSegments           Number of segments
//    sampleFreq            Sample frequency.
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when one of the specified
//                          pointers is NULL.
//    ippStsRangeErr        Indicates an error when sampleFreq is not a valid element
//                          of the enumerated type IppPCMFrequency.
//    ippStsBadArgErr       Indicates an error when numSubbands is less or
//                          equal to 0 or numSegment is less than or equal
//                          to 0 or frameSize is less than or equal to 0.
*/

IPPAPI(IppStatus, ippsSubbandControllerInit_EC_32f, (IppsSubbandControllerState_EC_32f *pState,
      int numSubbands, int frameSize, int numSegments, IppPCMFrequency sampleFreq))
IPPAPI(IppStatus, ippsSubbandControllerInit_EC_16s, (IppsSubbandControllerState_EC_16s *pState,
      int numSubbands, int frameSize, int numSegments, IppPCMFrequency sampleFreq))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsSubbandControllerUpdate_EC
//
//  Purpose:
//    Updates controller state. Returns step sizes.
//
//  Parameters:
//    pSrcRin               Pointer to receive-in signal frame.
//    pSrcSin               Pointer to send-in signal frame. Frame size is
//                          specified in ippsSubbandControllerInit function
//    ppSrcRinSubbandsHistory Pointer to an array of pointers to the most
//                          recent receive-in blocks. Size of array is equal
//                          to numSegments, specified in
//                          ippsSubbandControllerInit_EC function
//    pSrcSinSubbands       Pointer to subband representation of send-in
//                          signal frame (or NULL). Size of array =
//                          numSubbands, specified in
//                          ippsSubbandControllerInit_EC function
//    pDstStepSize          Pointer to step sizes. Length of vector =
//                          numSubbands, specified in
//                          ippsSubbandControllerInit_EC function
//    pState                Pointer to structure
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when pState, pRin, pSin,
//                          pRinSubbands or pStepSize is NULL.
*/

IPPAPI(IppStatus, ippsSubbandControllerUpdate_EC_32f, (const Ipp32f *pSrcRin, const Ipp32f *pSrcSin,
      const Ipp32fc **ppSrcRinSubbandsHistory, const Ipp32fc *pSrcSinSubbands,
      double *pDstStepSize, IppsSubbandControllerState_EC_32f *pState))
IPPAPI(IppStatus, ippsSubbandControllerUpdate_EC_16s, (const Ipp16s *pSrcRin, const Ipp16s *pSrcSin,
      const Ipp32sc **ppSrcRinSubbandsHistory, const Ipp32sc *pSrcSinSubbands,
      Ipp32s_EC_Sfs *pDstStepSize, IppsSubbandControllerState_EC_16s *pState))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsSubbandController_EC
//
//  Purpose:
//    Main controller function. Updates coefficients of filters. Returns
//    output gain coefficients
//
//  Parameters:
//    pSrcAdaptiveFilterErr Pointer to the adaptive filter error vector of
//                          length equal to numSubbands, specified in
//                          ippsSubbandControllerInit_EC function
//    pSrcFixedFilterErr    Pointer to errors of fixed filter. Length is
//                          equal to numSubbands
//    ppDstAdaptiveCoefs    Pointer to an array of pointers to the filter
//                          Length of array coefficients vectors =
//                          numSegments, specified in
//                          ippsSubbandControllerInit_EC
//    ppDstFixedCoefs       Pointer to an array of pointers to the filter
//                          Length of array coefficients vectors =
//                          numSegments, specified in
//                          ippsSubbandControllerInit_EC
//    pDstSGain             Pointer to send gain coefficient
//    pState                Pointer to SubbandController_EC state structure.
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when one of the specified
//                          pointers is NULL.
*/

IPPAPI(IppStatus, ippsSubbandController_EC_32f, (const Ipp32fc *pSrcAdaptiveFilterErr,
      const Ipp32fc *pSrcFixedFilterErr,
      Ipp32fc **ppDstAdaptiveCoefs, Ipp32fc **ppDstFixedCoefs,
      Ipp32f *pDstSGain, IppsSubbandControllerState_EC_32f *pState))
IPPAPI(IppStatus, ippsSubbandController_EC_16s, (const Ipp32sc *pSrcAdaptiveFilterErr,
      const Ipp32sc *pSrcFixedFilterErr,
      Ipp32sc **ppDstAdaptiveCoefs, Ipp32sc **ppDstFixedCoefs,
      Ipp16s *pDstSGain, IppsSubbandControllerState_EC_16s *pState))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsSubbandControllerReset_EC
//
//  Purpose:
//    Resets controller state
//
//  Parameters:
//    pState                Pointer to the structure.
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when one of the specified
//                          pointers is NULL.
*/

IPPAPI(IppStatus, ippsSubbandControllerReset_EC_32f, (IppsSubbandControllerState_EC_32f *pState))
IPPAPI(IppStatus, ippsSubbandControllerReset_EC_16s, (IppsSubbandControllerState_EC_16s *pState))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsFullbandControllerGetSize_EC
//
//  Purpose:
//    Returns size of the state structure
//
//  Parameters:
//    frameSize             Size of frame
//    tapLen                Number of tap values.
//    sampleFreq            Sample frequency
//    pSize                 Pointer to the computed buffer size value.
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when pSize NULL.
//    ippStsRangeErr        Indicates an error when sampleFreq is not a valid element
//                          of the enumerated type IppPCMFrequency.
//    ippStsBadArgErr       Indicates an error when frameSize is less or
//                          equal to 0 or tapLen is less than or equal to 0.
*/

IPPAPI(IppStatus, ippsFullbandControllerGetSize_EC_32f, (int frameSize,
      int tapLen, IppPCMFrequency sampleFreq, int *pSize))
IPPAPI(IppStatus, ippsFullbandControllerGetSize_EC_16s, (int frameSize,
      int tapLen, IppPCMFrequency sampleFreq, int *pSize))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsFullbandControllerInit_EC
//
//  Purpose:
//    Initializes the state structure
//
//  Parameters:
//    pState                Pointer to the memory buffer for the fullband
//                          controller state structure to be initialized.
//                          The size of the memory buffer to be acquired by
//                          ippsFullbandControllerGetSize_EC function via
//                          pSize parameter.
//    frameSize             Size of frame
//    tapLen                Number of tap values.
//    sampleFreq            Sample frequency.
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when one of the specified
//                          pointers is NULL.
//    ippStsRangeErr        Indicates an error when sampleFreq is not a valid element
//                          of the enumerated type IppPCMFrequency.
//    ippStsBadArgErr       Indicates an error when frameSize is less or
//                          equal to 0 or tapLen is less than or equal to 0.
*/

IPPAPI(IppStatus, ippsFullbandControllerInit_EC_32f, (IppsFullbandControllerState_EC_32f *pState,
      int frameSize, int tapLen, IppPCMFrequency sampleFreq))
IPPAPI(IppStatus, ippsFullbandControllerInit_EC_16s, (IppsFullbandControllerState_EC_16s *pState,
      int frameSize, int tapLen, IppPCMFrequency sampleFreq))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsFullbandControllerUpdate_EC
//
//  Purpose:
//    Updates controller state. Returns step sizes
//
//  Parameters:
//    pSrcRin               Pointer to receive-in signal history,length =
//                          tapLen + frameSize, tapLen and frameSize is
//                          specified in ippsFullbandControllerInit
//    pSrcSin               Pointer to send-in signal frame, frame size is
//                          specified in ippsFullbandControllerInit_EC
//    pDstStepSize          Pointer to step sizes, length = frame_size,
//                          specified in ippsFullbandControllerInit_EC
//    pState                Pointer to structure
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when pState, pRin, pSin, or
//                          pStepSize is NULL.
*/

IPPAPI(IppStatus, ippsFullbandControllerUpdate_EC_32f, (const Ipp32f *pSrcRin,
      const Ipp32f *pSrcSin, Ipp32f *pDstStepSize,
      IppsFullbandControllerState_EC_32f *pState))
IPPAPI(IppStatus, ippsFullbandControllerUpdate_EC_16s, (const Ipp16s *pSrcRin,
      const Ipp16s *pSrcSin, Ipp32s *pDstStepSize,
      IppsFullbandControllerState_EC_16s *pState))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsFullbandController_EC
//
//  Purpose:
//    Main controller function. Updates coefficients of filter . Returns
//    output gain coefficients
//
//  Parameters:
//    pState                Pointer to structure.
//    pAdaptiveFilterErr    Pointer to output of path with adaptive filter,
//                          length = frame size , specified in
//                          ippsFullbandControllerInit_EC
//    pFixedFilterErr       Pointer to output of path with fixed filter.
//                          length = frame size, specified in
//                          ippsFullbandControllerInit_EC
//    pAdaptiveCoefs        Pointer to the filter coefficients vectors.
//                          length = tapLength, specified in
//                          ippsFullbandControllerInit_EC
//    pFixedCoefs           Pointer to the filter coefficients vectors.
//                          length = tapLength, specified in
//                          ippsFullbandControllerInit_EC
//    pSGain                Pointer to send gain coefficient
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when one of the specified
//                          pointers is NULL.
*/

IPPAPI(IppStatus, ippsFullbandController_EC_32f, (const Ipp32f *pAdaptiveFilterErr,
      const Ipp32f *pFixedFilterErr,
      Ipp32f *pAdaptiveCoefs, Ipp32f *pFixedCoefs,
      Ipp32f *pSGain,
      IppsFullbandControllerState_EC_32f *pState))
IPPAPI(IppStatus, ippsFullbandController_EC_16s, (const Ipp16s *pAdaptiveFilterErr,
      const Ipp16s *pFixedFilterErr,
      Ipp16s *pAdaptiveCoefs, Ipp16s *pFixedCoefs,
      Ipp16s *pSGain,
      IppsFullbandControllerState_EC_16s *pState))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsFullbandControllerReset_EC
//
//  Purpose:
//    Resets controller state
//
//  Parameters:
//    pState                Pointer to the structure.
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when one of the specified
//                          pointers is NULL.
*/

IPPAPI(IppStatus, ippsFullbandControllerReset_EC_32f, (IppsFullbandControllerState_EC_32f *pState))
IPPAPI(IppStatus, ippsFullbandControllerReset_EC_16s, (IppsFullbandControllerState_EC_16s *pState))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsFIR_EC
//
//  Purpose:
//    Computes FIR filtering results.
//
//  Parameters:
//    pSrcSpchRef           Pointer to the source original (receive-out)
//                          signal of (tapLength + len) length
//    pSrcSpch              Pointer to the signal with echo path (send-in)
//    pDstSpch              Pointer to the destination "echo-free" signal
//                          (send-out)
//    len                   Length of source and destination signals
//    pSrcTaps              FIR filter taps vector
//    tapsLen               Number of taps of the FIR filter
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when one of the specified
//                          pointers is NULL.
*/

IPPAPI(IppStatus, ippsFIR_EC_32f, (const Ipp32f *pSrcSpchRef,
      const Ipp32f *pSrcSpch,
      Ipp32f *pDstSpch,
      int len,
      Ipp32f *pSrcCoef,
      int     tapLength))
IPPAPI(IppStatus, ippsFIR_EC_16s, (const Ipp16s *pSrcSpchRef,
      const Ipp16s *pSrcSpch,
      Ipp16s *pDstSpch,
      int len,
      Ipp16s *pSrcCoef,
      int     tapLength))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsNLMS_EC
//
//  Purpose:
//    Performs filtering with coefficients update.
//
//  Parameters:
//    pSrcSpchRef           Pointer to the source original (receive-out)
//                          signal of (tapLength + len) length.
//    pSrcSpch              Pointer to the signal with echo path (send-in)
//    pStepSize             Pointer to step sizes vector of length equal to
//                          len
//    pSrcDstErr            Pointer to last error value
//    pDstSpch              Pointer to the destination "echo-free" signal
//                          (send-out)
//    len                   Length of source and destination signals
//    pSrcDstTaps           FIR filter taps source and destination vector
//    tapsLen               Number of taps
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when one of the specified
//                          pointers is NULL.
*/

IPPAPI(IppStatus, ippsNLMS_EC_32f, (const Ipp32f *pSrcSpchRef,
      const Ipp32f *pSrcSpch,
      const Ipp32f *pStepSize,
      Ipp32f *pDstSpch,
      int len,
      Ipp32f *pSrcDstCoef,
      int tapLength,
      Ipp32f *pErr))
IPPAPI(IppStatus, ippsNLMS_EC_16s, (const Ipp16s *pSrcSpchRef,
      const Ipp16s *pSrcSpch,
      const Ipp32s *pStepSize,
      Ipp16s *pDstSpch,
      int len,
      Ipp16s *pSrcDstCoef,
      int tapLength,
      Ipp16s *pErr))

/* ///////////////////////////////////////////////////////////////////////////
// Name:
//   ippsFIRSubband_EC
//
// Purpose:
//   This function computes the filter output in AEC NLMS algorithm.
//
// Parameters:
//   ppSrcSignalIn          pointer to an array of pointers to the most
//                          recent input blocks (e.g., Xn, Xn-1,..., Xn-L+1).
//                          These are the complex-valued vectors that
//                          contain the FFT of the input signal stored in
//                          Intel IPP CCS format.
//   ppSrcCoefs             pointer to an array of pointers to the
//                          filter coefficients vectors. These are the
//                          complex-valued vectors containing the filter
//                          coefficients stored in Intel IPP CCS format.
//   numSegments            the number of filter segments (L).
//   len                    number of elements contained in each input
//                          vector and filter segment.
//   scaleFactor            saturation fixed scale factor
//   pDstSignalOut          pointer to the complex-valued filter output
//                          vector stored in Intel IPP CCS format.
//
// Returns:
//   ippStsNoErr            No Error.
//   ippStsNullPtrErr       ppSrcSignalIn, ppSrcCoefs or pDstSignalOut is null.
//   ippStsLengthErr        len is out of range.
//   ippStsRangeErr         numSegments or scaleFactor is out of range.
//
*/

IPPAPI(IppStatus, ippsFIRSubband_EC_32fc, (
      Ipp32fc **ppSrcSignalIn,
      Ipp32fc **ppSrcCoefs,
      Ipp32fc *pDstSignalOut,
      int     numSegments,
      int     len))

IPPAPI(IppStatus, ippsFIRSubband_EC_32sc_Sfs,(
      Ipp32sc **ppSrcSignalIn,
      Ipp32sc **ppSrcCoefs,
      Ipp32sc *pDstSignalOut,
      int     numSegments,
      int     len,
      int     scaleFactor))

/* ///////////////////////////////////////////////////////////////////////////
// Name:
//   ippsFIRSubbandCoeffUpdate_EC
//
// Purpose:
//   This function updates the coefficients of the AEC adaptive
//   filter designed based on NLMS algorithm.
// Parameters:
//   pSrcStepSize           pointer to the step size vector.
//                          ppSrcFilterInput- pointer to an array of pointers to the most
//                          recent input blocks (e.g., Xn, Xn-1, ..., Xn-L+1).
//                          These are the complex-valued vectors that
//                          contain the FFT of the input signal stored in
//                          Intel IPP CCS format.
//   ppSrcDstCoefsQ15       pointer to an array of pointers to the
//                          filter coefficient vectors. These are the
//                          complex-valued vectors containing the filter
//                          coefficients stored in Intel IPP CCS format.
//   pSrcError              pointer to the complex-valued vector
//                          containing the filter error stored in Intel
//                          IPP CCS format.
//   numSegments            the number of filter segments (L).
//   len                    number of elements contained in each input
//                          vector.
//   ppSrcDstCoefsQ15       pointer to an array of pointers to the
//                          filter coefficient vectors. It is In-Place
//                          variant.
//
//   Returns:
//     ippStsNoErr          No Error.
//     ippStsNullPtrErr     pSrcStepSize, ppSrcFilterInput, pSrcError or ppSrcDstCoefsQ15 is null.
//     ippStsLengthErr      len is out of range.
//     ippStsRangeErr       numSegments or scaleFactorCoef is out of range.
//     ippStsSizeErr        pSrcStepSize[indexVec].val is out of range.
//
*/

IPPAPI(IppStatus, ippsFIRSubbandCoeffUpdate_EC_32fc_I, (
                    const double *pSrcStepSize,
                    const Ipp32fc        **ppSrcFilterInput,
                    const Ipp32fc        *pSrcError,
                    Ipp32fc                **ppSrcDstCoefs,
                    int                    numSegments,
                    int                    len))

IPPAPI(IppStatus, ippsFIRSubbandCoeffUpdate_EC_32sc_I, (
                    const Ipp32s_EC_Sfs *pSrcStepSize,
                    const Ipp32sc        **ppSrcFilterInput,
                    const Ipp32sc        *pSrcError,
                    Ipp32sc                **ppSrcDstCoefsQ15,
                    int                    numSegments,
                    int                    len,
                    int                 scaleFactorCoef))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsToneDetectGetStateSize_EC
//
//  Purpose:
//    Returns size of the state structure
//
//  Parameters:
//    sampleFreq            Sample frequency.
//    pSize                 Pointer to the computed buffer size value
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsNullPtrErr      Indicates an error when one of the specified
//                          pointers is NULL.
//    ippStsRangeErr        Indicates an error when sampleFreq is not a valid element
//                          of the enumerated type IppPCMFrequency.
//    ippStsRangeErr        Indicates an error when sampleFreq is not a
//                          valid element of the enumerated type IppFrequency
//
*/

IPPAPI(IppStatus, ippsToneDetectGetStateSize_EC_32f, (IppPCMFrequency sampleFreq, int *pSize))
IPPAPI(IppStatus, ippsToneDetectGetStateSize_EC_16s, (IppPCMFrequency sampleFreq, int *pSize))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsToneDetectInit_EC
//
//  Purpose:
//    Initializes the state structure
//
//  Parameters:
//    pState                Pointer to the memory buffer to be initialized
//                          as the tone detector state structure. The size
//                          of memory to be acquired by the
//                          ippsToneDetectGetStateSize_EC function via pSize
//                          parameter.
//    sampleFreq            Sample frequency
//
//  Returns:
//    ippStsNoErr           Indicates no error.
//    ippStsRangeErr        Indicates an error when sampleFreq is not a valid element
//                          of the enumerated type IppPCMFrequency.
//    ippStsRangeErr        Indicates an error when sampleFreq is not a
//                          valid element of the enumerated type IppFrequency
*/

IPPAPI(IppStatus, ippsToneDetectInit_EC_32f, (IppsToneDetectState_EC_32f *pState,
      IppPCMFrequency sampleFreq))
IPPAPI(IppStatus, ippsToneDetectInit_EC_16s, (IppsToneDetectState_EC_16s *pState,
      IppPCMFrequency sampleFreq))

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsToneDetect_EC
//
//  Purpose:
//    Detects signal 2100 Hz with every 450 ms phase reversal
//
//  Parameters:
//    pSignal               Pointer to signal vector.
//    len                   Number of samples in signal vector
//    pResult               Pointer to result value (not zero means tone was
//                          detected)
//    pState                Pointer to the tone detector state structure.
//
//  Returns:
//    ippStsNoErr           Indicates no error.
*/

IPPAPI(IppStatus, ippsToneDetect_EC_32f, (const Ipp32f *pSignal,
      int len, int *pResult,
      IppsToneDetectState_EC_32f *pState))
IPPAPI(IppStatus, ippsToneDetect_EC_16s, (const Ipp16s *pSignal,
      int len, int *pResult,
      IppsToneDetectState_EC_16s *pState))

/* /////////////////////////////////////////////////////////////////////////////
//                         Echo Canceller end
///////////////////////////////////////////////////////////////////////////// */

#ifdef __cplusplus
}
#endif

#if defined (_IPP_STDCALL_CDECL)
  #undef  _IPP_STDCALL_CDECL
  #define __stdcall __cdecl
#endif

#endif /* __IPPSC_H__ */
/* ////////////////////////////// End of file /////////////////////////////// */


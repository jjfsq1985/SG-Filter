#pragma once

#if defined(SG_FILTER_EXPORTS)
#define SF_FILTER_API __declspec(dllexport)
#else
#define SF_FILTER_API __declspec(dllimport)
#endif

#ifdef  __cplusplus
#define MODBUS_BEGIN_DECLS  extern "C" {
#define MODBUS_END_DECLS    }
#else
#define MODBUS_BEGIN_DECLS
#define MODBUS_END_DECLS
#endif


MODBUS_BEGIN_DECLS


SF_FILTER_API bool sgFilter(double *pDataIn, int nDataLen, double *pDataOut);


MODBUS_END_DECLS
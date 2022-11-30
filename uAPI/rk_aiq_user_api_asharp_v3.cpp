/*
 *  Copyright (c) 2019 Rockchip Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "include/uAPI/rk_aiq_user_api_asharp_v3.h"
#include "RkAiqHandleIntV21.h"

RKAIQ_BEGIN_DECLARE

#ifdef RK_SIMULATOR_HW
#define CHECK_USER_API_ENABLE
#endif

XCamReturn
rk_aiq_user_api_asharpV3_SetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_sharp_attrib_v3_t* attr)
{
    CHECK_USER_API_ENABLE2(sys_ctx);
    CHECK_USER_API_ENABLE(RK_AIQ_ALGO_TYPE_ASHARP);
    RkAiqAsharpV3HandleInt* algo_handle =
        algoHandle<RkAiqAsharpV3HandleInt>(sys_ctx, RK_AIQ_ALGO_TYPE_ASHARP);

    if (algo_handle) {
        return algo_handle->setAttrib(attr);
    }

    return XCAM_RETURN_NO_ERROR;
}

XCamReturn
rk_aiq_user_api_asharpV3_GetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, rk_aiq_sharp_attrib_v3_t* attr)
{
    RkAiqAsharpV3HandleInt* algo_handle =
        algoHandle<RkAiqAsharpV3HandleInt>(sys_ctx, RK_AIQ_ALGO_TYPE_ASHARP);

    if (algo_handle) {
        return algo_handle->getAttrib(attr);
    }

    return XCAM_RETURN_NO_ERROR;
}

XCamReturn
rk_aiq_user_api_asharpV3_SetStrength(const rk_aiq_sys_ctx_t* sys_ctx, float fPercnt)
{
    XCamReturn ret = XCAM_RETURN_NO_ERROR;
    RKAIQ_API_SMART_LOCK(sys_ctx);


    RkAiqAsharpV3HandleInt* algo_handle =
        algoHandle<RkAiqAsharpV3HandleInt>(sys_ctx, RK_AIQ_ALGO_TYPE_ASHARP);
    if (algo_handle) {
        ret = algo_handle->setStrength(fPercnt);
    }


    return ret;
}


XCamReturn
rk_aiq_user_api_asharpV3_GetStrength(const rk_aiq_sys_ctx_t* sys_ctx, float *pPercnt)
{
    XCamReturn ret = XCAM_RETURN_NO_ERROR;
    RKAIQ_API_SMART_LOCK(sys_ctx);


    RkAiqAsharpV3HandleInt* algo_handle =
        algoHandle<RkAiqAsharpV3HandleInt>(sys_ctx, RK_AIQ_ALGO_TYPE_ASHARP);
    if (algo_handle) {
        ret = algo_handle->getStrength(pPercnt);
    }

    return ret;
}



RKAIQ_END_DECLARE

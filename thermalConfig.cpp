/*
 * Copyright (c) 2020,2021 The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *	* Redistributions of source code must retain the above copyright
 *	  notice, this list of conditions and the following disclaimer.
 *	* Redistributions in binary form must reproduce the above
 *	  copyright notice, this list of conditions and the following
 *	  disclaimer in the documentation and/or other materials provided
 *	  with the distribution.
 *	* Neither the name of The Linux Foundation nor the names of its
 *	  contributors may be used to endorse or promote products derived
 *	  from this software without specific prior written permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Changes from Qualcomm Innovation Center are provided under the following license:
 * Copyright (c) 2022-2024 Qualcomm Innovation Center, Inc. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

 /* Changes from Qualcomm Innovation Center are provided under the following license:

Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
SPDX-License-Identifier: BSD-3-Clause-Clear */

#include <unordered_map>
#include <android-base/logging.h>
#include <aidl/android/hardware/thermal/BnThermal.h>

#include "thermalData.h"
#include "thermalConfig.h"

namespace aidl {
namespace android {
namespace hardware {
namespace thermal {

	constexpr std::string_view socIDPath("/sys/devices/soc0/soc_id");

	std::vector<std::string> cpu_sensors_bengal =
	{
		"cpuss-2-usr",
		"cpuss-2-usr",
		"cpuss-2-usr",
		"cpuss-2-usr",
		"cpu-1-0-usr",
		"cpu-1-1-usr",
		"cpu-1-2-usr",
		"cpu-1-3-usr",
	};

	std::vector<struct target_therm_cfg> sensor_cfg_bengal =
	{
		{
			TemperatureType::CPU,
			cpu_sensors_bengal,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpu-usr" },
			"GPU",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "xo-therm-usr" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
		{
			TemperatureType::BCL_VOLTAGE,
			{ "pmi632-vbat-lvl0" },
			"vbat",
			{
			[SEVERE] = 3000,
			[SHUTDOWN] = 2800,
			},
			false,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pmi632-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 4000,
			[SHUTDOWN] = 4200,
			},
			true,
		},
		{
			TemperatureType::BCL_PERCENTAGE,
			{ "socd" },
			"socd",
			{
			[SEVERE] = 90,
			[SHUTDOWN] = 98,
			},
			true,
		},
	};

	std::vector<std::string> cpu_sensors_khaje =
	{
		"cpuss-0",
		"cpuss-1",
		"cpuss-2",
		"cpu-1-0",
		"cpu-1-1",
		"cpu-1-2",
		"cpu-1-3",
	};

	std::vector<struct target_therm_cfg> sensor_cfg_khaje =
	{
		{
			TemperatureType::CPU,
			cpu_sensors_khaje,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpu" },
			"GPU",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "xo-therm" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
		{
			TemperatureType::BCL_VOLTAGE,
			{ "pm7250b-vbat-lvl0" },
			"vbat",
			{
			[SEVERE] = 3000,
			[SHUTDOWN] = 2800,
			},
			false,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pm7250b-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 5500,
			[SHUTDOWN] = 6000,
			},
			true,
		},
		{
			TemperatureType::BCL_PERCENTAGE,
			{ "socd" },
			"socd",
			{
			[SEVERE] = 90,
			[SHUTDOWN] = 98,
			},
			true,
		},
	};

	std::vector<std::string> cpu_sensors_trinket =
	{
		"cpuss-0-usr",
		"cpuss-0-usr",
		"cpuss-0-usr",
		"cpuss-0-usr",
		"cpu-1-0-usr",
		"cpu-1-1-usr",
		"cpu-1-2-usr",
		"cpu-1-3-usr",
	};

	std::vector<struct target_therm_cfg> sensor_cfg_trinket =
	{
		{
			TemperatureType::CPU,
			cpu_sensors_trinket,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpu-usr" },
			"GPU",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "xo-therm-adc" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
		{
			TemperatureType::BCL_VOLTAGE,
			{ "pmi632-vbat-lvl0" },
			"vbat",
			{
			[SEVERE] = 3000,
			[SHUTDOWN] = 2800,
			},
			false,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pmi632-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 4000,
			[SHUTDOWN] = 4200,
			},
			true,
		},
		{
			TemperatureType::BCL_PERCENTAGE,
			{ "socd" },
			"socd",
			{
			[SEVERE] = 90,
			[SHUTDOWN] = 98,
			},
			true,
		},
	};

	std::vector<std::string> cpu_sensors_lito =
	{
		"cpu-0-0-usr",
		"cpu-0-1-usr",
		"cpu-0-2-usr",
		"cpu-0-3-usr",
		"cpu-0-4-usr",
		"cpu-0-5-usr",
		"cpu-1-0-usr",
		"cpu-1-2-usr",
	};

	std::vector<struct target_therm_cfg> sensor_cfg_lito =
	{
		{
			TemperatureType::CPU,
			cpu_sensors_lito,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0-usr" },
			"GPU",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "xo-therm-usr" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pm7250b-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 4500,
			[SHUTDOWN] = 5000,
			},
			true,
		},
		{
			TemperatureType::BCL_VOLTAGE,
			{ "pm7250b-vbat-lvl0" },
			"vbat",
			{
			[SEVERE] = 3200,
			[SHUTDOWN] = 3000,
			},
			false,
		},
		{
			TemperatureType::BCL_PERCENTAGE,
			{ "socd" },
			"socd",
			{
			[SEVERE] = 90,
			[SHUTDOWN] = 98,
			},
			true,
		},
	};

	std::vector<struct target_therm_cfg> sensor_cfg_sdmmagpie =
	{
		{
			TemperatureType::CPU,
			cpu_sensors_lito,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0-usr" },
			"GPU",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "xo-therm-adc" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
		{
			TemperatureType::BCL_VOLTAGE,
			{ "pm6150-vbat-lvl0" },
			"vbat",
			{
			[SEVERE] = 3000,
			[SHUTDOWN] = 2800,
			},
			false,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pm6150-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 5500,
			[SHUTDOWN] = 6000,
			},
			true,
		},
		{
			TemperatureType::BCL_PERCENTAGE,
			{ "socd" },
			"socd",
			{
			[SEVERE] = 90,
			[SHUTDOWN] = 98,
			},
			true,
		},
	};

	std::vector<struct target_therm_cfg> sensor_cfg_holi =
	{
		{
			TemperatureType::CPU,
			cpu_sensors_lito,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0-usr" },
			"gpu0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1-usr" },
			"gpu1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "quiet-therm-usr" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pm7250b-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 5500,
			[SHUTDOWN] = 6000,
			},
			true,
		},
	};

	std::vector<std::string> cpu_sensors_kona =
	{
		"cpu-0-0-usr",
		"cpu-0-1-usr",
		"cpu-0-2-usr",
		"cpu-0-3-usr",
		"cpu-1-0-usr",
		"cpu-1-1-usr",
		"cpu-1-2-usr",
		"cpu-1-3-usr",
	};

	std::vector<struct target_therm_cfg>  sensor_cfg_msmnile = {
		{
			TemperatureType::CPU,
			cpu_sensors_kona,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0-usr" },
			"gpu0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1-usr" },
			"gpu1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "xo-therm" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pm8150b-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 4500,
			[SHUTDOWN] = 5000,
			},
			true,
		},
		{
			TemperatureType::BCL_VOLTAGE,
			{ "pm8150b-vbat-lvl0" },
			"vbat",
			{
			[SEVERE] = 3200,
			[SHUTDOWN] = 3000,
			},
			false,
		},
		{
			TemperatureType::BCL_PERCENTAGE,
			{ "socd" },
			"socd",
			{
			[SEVERE] = 90,
			[SHUTDOWN] = 98,
			},
			true,
		},
	};

	std::vector<struct target_therm_cfg>  kona_common = {
		{
			TemperatureType::CPU,
			cpu_sensors_kona,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0-usr" },
			"GPU0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1-usr" },
			"GPU1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "skin-msm-therm-usr" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		}
	};

	std::vector<struct target_therm_cfg>  kona_specific = {
		{
			TemperatureType::BCL_CURRENT,
			{ "pm8150b-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 4500,
			[SHUTDOWN] = 5000,
			},
			true,
		},
		{
			TemperatureType::BCL_VOLTAGE,
			{ "pm8150b-vbat-lvl0" },
			"vbat",
			{
			[SEVERE] = 3200,
			[SHUTDOWN] = 3000,
			},
			false,
		},
		{
			TemperatureType::BCL_PERCENTAGE,
			{ "socd" },
			"socd",
			{
			[SEVERE] = 90,
			[SHUTDOWN] = 98,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "npu-usr" },
			"npu",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
	};

	std::vector<std::string> cpu_sensors_lahaina =
	{
		"cpu-0-0",
		"cpu-0-1",
		"cpu-0-2",
		"cpu-0-3",
		"cpu-1-0",
		"cpu-1-2",
		"cpu-1-4",
		"cpu-1-6",
	};

	std::vector<struct target_therm_cfg>  lahaina_common = {
		{
			TemperatureType::CPU,
			cpu_sensors_lahaina,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0-usr" },
			"GPU0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1-usr" },
			"GPU1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pm8350b-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 6000,
			[SHUTDOWN] = 7500,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-0-usr" },
			"nsp0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-1-usr" },
			"nsp1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-2-usr" },
			"nsp2",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
	};

	std::vector<struct target_therm_cfg>  lahaina_specific = {
		{
			TemperatureType::SKIN,
			{ "xo-therm-usr" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
	};

	std::vector<struct target_therm_cfg>  shima_specific = {
		{
			TemperatureType::SKIN,
			{ "quiet-therm-usr" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
	};

	std::vector<struct target_therm_cfg>  sensor_cfg_yupik = {
		{
			TemperatureType::CPU,
			cpu_sensors_lahaina,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0" },
			"GPU0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1" },
			"GPU1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-0" },
			"nsp0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-1" },
			"nsp1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "quiet-therm" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
	};

	std::vector<std::string> cpu_sensors_waipio =
	{
		"cpu-0-0",
		"cpu-0-1",
		"cpu-0-2",
		"cpu-0-3",
		"cpu-1-0",
		"cpu-1-2",
		"cpu-1-4",
		"cpu-1-6",
	};

	std::vector<struct target_therm_cfg>  waipio_common = {
		{
			TemperatureType::CPU,
			cpu_sensors_waipio,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0" },
			"GPU0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1" },
			"GPU1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-0" },
			"nsp0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-1" },
			"nsp1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-2" },
			"nsp2",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
	};

	std::vector<struct target_therm_cfg>  waipio_specific = {
		{
			TemperatureType::BCL_CURRENT,
			{ "pm8350b-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 6000,
			[SHUTDOWN] = 7500,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "xo-therm" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
	};

	std::vector<std::string> cpu_sensors_kalama =
	{
		"cpu-0-0",
		"cpu-0-1",
		"cpu-0-2",
		"cpu-1-0",
		"cpu-1-2",
		"cpu-1-4",
		"cpu-1-6",
		"cpu-1-8",
	};

	std::vector<struct target_therm_cfg>  kalama_common = {
		{
			TemperatureType::CPU,
			cpu_sensors_kalama,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0" },
			"GPU0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1" },
			"GPU1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-2" },
			"GPU2",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-3" },
			"GPU3",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-4" },
			"GPU4",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-5" },
			"GPU5",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-6" },
			"GPU6",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-7" },
			"GPU7",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-0" },
			"nsp0",
			{
			[SEVERE] = 100000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-1" },
			"nsp1",
			{
			[SEVERE] = 100000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-2" },
			"nsp2",
			{
			[SEVERE] = 100000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-3" },
			"nsp3",
			{
			[SEVERE] = 100000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
	};

	std::vector<struct target_therm_cfg>  kalama_specific = {
		{
			TemperatureType::BCL_CURRENT,
			{ "pm8550b-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 9000,
			[SHUTDOWN] = 10000,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "skin-msm-therm" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
	};

	std::vector<struct target_therm_cfg>  diwali_specific = {
		{
			TemperatureType::BCL_CURRENT,
			{ "pm8350b-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 6000,
			[SHUTDOWN] = 7500,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "quiet-therm" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
	};

	struct target_therm_cfg bat_conf = {
		TemperatureType::BATTERY,
		{ "battery" },
		"battery",
		{
		[SEVERE] = 80000,
		[SHUTDOWN] = 90000,
		},
		true,
		true,
	};

	std::vector<struct target_therm_cfg> bcl_conf = {
		{
			TemperatureType::BCL_VOLTAGE,
			{ "vbat" },
			"vbat",
			{
			[SEVERE] = 3200,
			[SHUTDOWN] = 3000,
			},
			false,
			true,
		},
		{
			TemperatureType::BCL_PERCENTAGE,
			{ "socd" },
			"socd",
			{
			[SEVERE] = 90,
			[SHUTDOWN] = 99,
			},
			true,
		},
	};

	std::vector<std::string> cpu_sensors_pineapple = {
		"cpu-0-0-0",
		"cpu-0-1-0",
		"cpu-2-0-0",
		"cpu-2-1-0",
		"cpu-2-2-0",
		"cpu-1-0-0",
		"cpu-1-1-0",
		"cpu-1-2-0",
	};

	std::vector<struct target_therm_cfg> pineapple_common = {
		{
			TemperatureType::CPU,
			cpu_sensors_pineapple,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0" },
			"GPU0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1" },
			"GPU1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-2" },
			"GPU2",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-3" },
			"GPU3",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-4" },
			"GPU4",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-5" },
			"GPU5",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-6" },
			"GPU6",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-7" },
			"GPU7",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-0" },
			"nsp0",
			{
			[SEVERE] = 100000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-1" },
			"nsp1",
			{
			[SEVERE] = 100000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-0" },
			"nsp2",
			{
			[SEVERE] = 100000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-1" },
			"nsp3",
			{
			[SEVERE] = 100000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-2" },
			"nsp4",
			{
			[SEVERE] = 100000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-3" },
			"nsp5",
			{
			[SEVERE] = 100000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
	};

	std::vector<struct target_therm_cfg>  pineapple_specific = {
		{
			TemperatureType::BCL_CURRENT,
			{ "pm8550b-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 9000,
			[SHUTDOWN] = 10000,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "skin-msm-therm" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
	};

	std::vector<std::string> cpu_sensors_sun = {
		"cpu-0-0-0",
		"cpu-0-1-0",
		"cpu-0-2-0",
		"cpu-0-3-0",
		"cpu-0-4-0",
		"cpu-0-5-0",
		"cpu-1-0-0",
		"cpu-1-1-0",
	};

	std::vector<struct target_therm_cfg> sun_profile0 = {
		{
			TemperatureType::CPU,
			cpu_sensors_sun,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0" },
			"GPU0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1" },
			"GPU1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-2" },
			"GPU2",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-3" },
			"GPU3",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-4" },
			"GPU4",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-5" },
			"GPU5",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-6" },
			"GPU6",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-7" },
			"GPU7",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-0" },
			"nsp0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-1" },
			"nsp1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-2" },
			"nsp2",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-0" },
			"nsp3",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-1" },
			"nsp4",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-2" },
			"nsp5",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-3" },
			"nsp6",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
	};

	std::vector<struct target_therm_cfg> sun_profile1 = {
		{
			TemperatureType::CPU,
			cpu_sensors_sun,
			"",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0" },
			"GPU0",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1" },
			"GPU1",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-2" },
			"GPU2",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-3" },
			"GPU3",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-4" },
			"GPU4",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-5" },
			"GPU5",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-6" },
			"GPU6",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-7" },
			"GPU7",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-0" },
			"nsp0",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-1" },
			"nsp1",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-2" },
			"nsp2",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-0" },
			"nsp3",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-1" },
			"nsp4",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-2" },
			"nsp5",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-3" },
			"nsp6",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
	};

	std::vector<struct target_therm_cfg> sun_specific = {
		{
			TemperatureType::BCL_CURRENT,
			{ "pmih010x-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 13500,
			[SHUTDOWN] = 15000,
			},
			true,
			true,
		},
		{
			TemperatureType::SKIN,
			{ "sys-therm-2" },
			"skin",
			{
			[LIGHT] = 36500,
			[MODERATE] = 40000,
			[SEVERE] = 46500,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
	};

	std::vector<std::string> cpu_sensors_parrot =
	{
		"cpu-0-0",
		"cpu-0-1",
		"cpu-0-2",
		"cpu-0-3",
		"cpu-1-0",
		"cpu-1-2",
		"cpu-1-4",
		"cpu-1-6",
	};

	std::vector<struct target_therm_cfg>  parrot_common = {
		{
			TemperatureType::CPU,
			cpu_sensors_parrot,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0" },
			"GPU0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1" },
			"GPU1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-0" },
			"nsp0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::NPU,
			{ "nspss-1" },
			"nsp1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0" },
			"GPU0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1" },
			"GPU1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-2" },
			"GPU2",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-3" },
			"GPU3",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-4" },
			"GPU4",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-5" },
			"GPU5",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-6" },
			"GPU6",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
	};

	std::vector<struct target_therm_cfg>  parrot_specific = {
		{
			TemperatureType::BCL_CURRENT,
			{ "pm7250b-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 6000,
			[SHUTDOWN] = 7500,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "xo-therm" },
			"skin",
			{
			[LIGHT] = 50000,
			[MODERATE] = 52000,
			[SEVERE] = 55000,
			[CRITICAL] = 60000,
			[EMERGENCY] = 65000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
	};

	std::vector<std::string> cpu_sensors_monaco = {
		"cpuss-0",
		"cpuss-1",
		"cpuss-0",
		"cpuss-1",
		"cpuss-0",
		"cpuss-1",
		"cpuss-0",
		"cpuss-1",
	};

	std::vector<struct target_therm_cfg> sensor_cfg_monaco = {
		{
			TemperatureType::CPU,
			cpu_sensors_monaco,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpu" },
			"gpu",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
		},
		{
			TemperatureType::SKIN,
			{ "pa-therm0" },
			"skin",
			{
			[LIGHT] = 40000,
			[MODERATE] = 42000,
			[SEVERE] = 45000,
			[CRITICAL] = 50000,
			[EMERGENCY] = 55000,
			[SHUTDOWN] = 95000,
			},
			true,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pm5100-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 1100,
			[SHUTDOWN] = 1500,
			},
			true,
		},
	};

	std::vector<std::string> cpu_sensors_canoe = {
		"cpu-0-0-1",
		"cpu-0-1-1",
		"cpu-0-2-1",
		"cpu-0-3-1",
		"cpu-0-4-1",
		"cpu-0-5-1",
		"cpu-1-0-1",
		"cpu-1-1-1",
	};

	std::vector<struct target_therm_cfg> canoe_common = {
		{
			TemperatureType::CPU,
			cpu_sensors_canoe,
			"",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0" },
			"GPU0",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1" },
			"GPU1",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-2" },
			"GPU2",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-3" },
			"GPU3",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-4" },
			"GPU4",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-5" },
			"GPU5",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-6" },
			"GPU6",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-7" },
			"GPU7",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-8" },
			"GPU8",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-9" },
			"GPU9",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-10" },
			"GPU10",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-0" },
			"nsp0",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-1" },
			"nsp1",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-2" },
			"nsp2",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-3" },
			"nsp3",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-0" },
			"nsp4",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-1" },
			"nsp5",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-2" },
			"nsp6",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-3" },
			"nsp7",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
	};

	std::vector<struct target_therm_cfg> canoe_specific = {
		{
			TemperatureType::BCL_CURRENT,
			{ "pmih010x-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 13500,
			[SHUTDOWN] = 15000,
			},
			true,
			true,
		},
		{
			TemperatureType::SKIN,
			{ "sys-therm-0" },
			"skin",
			{
			[LIGHT] = 48000,
			[MODERATE] = 49000,
			[SEVERE] = 50000,
			[CRITICAL] = 60000,
			[EMERGENCY] = 61000,
			[SHUTDOWN] = 90000,
			},
			true,
			true,
			true,
			{ "sys-therm-0" },
			{ 0.76 },
			{ "sys-therm-0" },
			40000,
			38000,
			5160,
			5000,
		},
	};

	std::vector<std::string> cpu_sensors_hamoa = {
		"cpu-0-0-1-thermal",
		"cpu-0-1-1-thermal",
		"cpu-0-2-1-thermal",
		"cpu-0-3-1-thermal",
		"cpu-1-0-1-thermal",
		"cpu-1-1-1-thermal",
		"cpu-1-2-1-thermal",
		"cpu-1-3-1-thermal",
		"cpu-2-0-1-thermal",
		"cpu-2-1-1-thermal",
		"cpu-2-2-1-thermal",
		"cpu-2-3-1-thermal",
	};

	std::vector<struct target_therm_cfg> hamoa_common = {
		{
			TemperatureType::CPU,
			cpu_sensors_hamoa,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0-thermal" },
			"GPU0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1-thermal" },
			"GPU1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-2-thermal" },
			"GPU2",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-3-thermal" },
			"GPU3",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-4-thermal" },
			"GPU4",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-5-thermal" },
			"GPU5",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-6-thermal" },
			"GPU6",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-7-thermal" },
			"GPU7",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsp-0-thermal" },
			"nsp0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsp-1-thermal" },
			"nsp1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsp-2-thermal" },
			"nsp2",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsp-3-thermal" },
			"nsp3",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
	};

	std::vector<struct target_therm_cfg> hamoa_specific = {
		{
			TemperatureType::BCL_CURRENT,
			{ "smb2360_0-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 13500,
			[SHUTDOWN] = 15000,
			},
			true,
			true,
		},
		{
			TemperatureType::SKIN,
			{ "sys-therm-2" },
			"skin",
			{
			[LIGHT] = 48000,
			[MODERATE] = 49000,
			[SEVERE] = 50000,
			[CRITICAL] = 60000,
			[EMERGENCY] = 61000,
			[SHUTDOWN] = 90000,
			},
			true,
			true,
		},
	};

	std::vector<std::string> cpu_sensors_vienna = {
		"cpu-0-0-0",
		"cpu-0-0-1",
		"cpu-1-0-0",
		"cpu-1-0-1",
		"cpu-0-0-0",
		"cpu-0-0-1",
		"cpu-1-0-0",
		"cpu-1-0-1",
	};

	std::vector<struct target_therm_cfg> vienna_common = {
		{
			TemperatureType::CPU,
			cpu_sensors_vienna,
			"",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0" },
			"GPU0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1" },
			"GPU1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-0" },
			"nsp0",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-0" },
			"nsp1",
			{
			[SEVERE] = 95000,
			[SHUTDOWN] = 115000,
			},
			true,
			true,
		},
	};

	std::vector<struct target_therm_cfg>  vienna_specific = {
		{
			TemperatureType::BCL_CURRENT,
			{ "pmw6100-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 2730,
			[SHUTDOWN] = 3200,
			},
			true,
			true,
		},
		{
			TemperatureType::SKIN,
			{ "sys-therm-0" },
			"skin",
			{
			[LIGHT] = 48000,
			[MODERATE] = 49000,
			[SEVERE] = 50000,
			[CRITICAL] = 60000,
			[EMERGENCY] = 61000,
			[SHUTDOWN] = 90000,
			},
			true,
			true,
		},
	};

	std::vector<std::string> cpu_sensors_alor = {
		"cpu-0-0-1",
		"cpu-0-1-1",
		"cpu-0-2-1",
		"cpu-0-3-1",
		"cpu-0-4-1",
		"cpu-0-5-1",
		"cpu-1-0-1",
		"cpu-1-1-1",
	};

	std::vector<struct target_therm_cfg> alor_common = {
		{
			TemperatureType::CPU,
			cpu_sensors_alor,
			"",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-0" },
			"GPU0",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-1" },
			"GPU1",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-2" },
			"GPU2",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-3" },
			"GPU3",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-4" },
			"GPU4",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-5" },
			"GPU5",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-6" },
			"GPU6",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::GPU,
			{ "gpuss-7" },
			"GPU7",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-0" },
			"nsp0",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-1" },
			"nsp1",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphvx-2" },
			"nsp2",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-0" },
			"nsp4",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
		{
			TemperatureType::NPU,
			{ "nsphmx-1" },
			"nsp5",
			{
			[SEVERE] = 105000,
			[SHUTDOWN] = 125000,
			},
			true,
			true,
		},
	};

	std::vector<struct target_therm_cfg> alor_specific = {
		{
			TemperatureType::SKIN,
			{ "sys-therm-0" },
			"skin",
			{
			[LIGHT] = 48000,
			[MODERATE] = 49000,
			[SEVERE] = 50000,
			[CRITICAL] = 60000,
			[EMERGENCY] = 61000,
			[SHUTDOWN] = 90000,
			},
			true,
			true,
			true,
			{ "sys-therm-0" },
			{ 0.80 },
			{ "sys-therm-0" },
			40000,
			38000,
			3235,
			5000,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pmih010x-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 11000,
			[SHUTDOWN] = 11800,
			},
			true,
			true,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pm7550ba-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 11000,
			[SHUTDOWN] = 11800,
			},
			true,
			true,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pmih010x-2s-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 5000,
			[SHUTDOWN] = 7000,
			},
			true,
			true,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pm7550ba-2s-ibat-lvl0 " },
			"ibat",
			{
			[SEVERE] = 5000,
			[SHUTDOWN] = 7000,
			},
			true,
			true,
		},
		{
			TemperatureType::BCL_CURRENT,
			{ "pmiv010x-ibat-lvl0" },
			"ibat",
			{
			[SEVERE] = 11000,
			[SHUTDOWN] = 11800,
			},
			true,
			true,
		},
	};

	const std::unordered_map<int, std::vector<struct target_therm_cfg>>
		msm_soc_map = {
		{417, sensor_cfg_bengal}, // bengal
		{420, sensor_cfg_bengal},
		{444, sensor_cfg_bengal},
		{445, sensor_cfg_bengal},
		{469, sensor_cfg_bengal},
		{470, sensor_cfg_bengal},
		{518, sensor_cfg_khaje},  //khaje
		{394, sensor_cfg_trinket},
		{467, sensor_cfg_trinket},
		{468, sensor_cfg_trinket},
		{400, sensor_cfg_lito}, // lito
		{440, sensor_cfg_lito},
		{407, sensor_cfg_lito}, // atoll
		{365, sensor_cfg_sdmmagpie},
		{366, sensor_cfg_sdmmagpie},
		{434, sensor_cfg_lito}, // lagoon
		{435, sensor_cfg_lito},
		{459, sensor_cfg_lito},
		{476, sensor_cfg_lito}, // orchid
		{339, sensor_cfg_msmnile},
		{361, sensor_cfg_msmnile},
		{362, sensor_cfg_msmnile},
		{367, sensor_cfg_msmnile},
		{356, kona_common}, // kona
		{415, lahaina_common}, // lahaina
		{439, lahaina_common}, // lahainap
		{456, lahaina_common}, // lahaina-atp
		{501, lahaina_common},
		{502, lahaina_common},
		{450, lahaina_common}, // shima
		{454, sensor_cfg_holi}, // holi
		{475, sensor_cfg_yupik}, // yupik
		{515, sensor_cfg_yupik}, // YUPIK-LTE
		{497, sensor_cfg_yupik}, // YUPIK-iot mdm
		{498, sensor_cfg_yupik}, // YUPIK-iot
		{575, sensor_cfg_yupik}, // YUPIK 5430 mdm
		{576, sensor_cfg_yupik}, // YUPIK 5430
		{457, waipio_common}, //Waipio
		{482, waipio_common}, //Waipio
		{552, waipio_common}, //Waipio-LTE
		{506, waipio_common}, //diwali
		{530, waipio_common}, // cape
		{531, waipio_common}, // cape
		{540, waipio_common}, // cape
		{519, kalama_common}, //Kalama
		{536, kalama_common}, //Kalamap
		{600, kalama_common}, //Kalama_sg
		{601, kalama_common}, //Kalamap_sg
		{557, pineapple_common}, //Pineapple
		{577, pineapple_common}, //Pineapplep
		{618, sun_specific}, //Sun
		{639, sun_specific}, //Sunp
		{537, parrot_common}, //Netrani mobile
		{583, parrot_common}, //Netrani mobile without modem
		{613, parrot_common}, //Netrani APQ
		{631, parrot_common},
		{633, parrot_common}, //Netrani Gaming SKU with modem
		{634, parrot_common}, //Netrani Gaming SKU without modem
		{638, parrot_common}, //SM7435P
		{663, parrot_common}, //SM7435
		{486, sensor_cfg_monaco}, // monaco
		{517, sensor_cfg_monaco}, // monaco
		{660, canoe_common}, //Canoe
		{661, canoe_common}, //Canoep
		{722, canoe_common}, //Alana
		{723, canoe_common}, //Alana APQ
		{743, canoe_common}, //Gaming SKU
		{669, vienna_common}, //SW6100
		{670, vienna_common}, //SW6100P
		{685, alor_common}, // Molokai
		{727, alor_common}, // Molokai APQ
		{555, hamoa_common}, // Hamoa
	};

	const std::unordered_map<int, std::vector<struct target_therm_cfg>>
		msm_soc_specific = {
		{356, kona_specific}, // kona
		{415, lahaina_specific}, // lahaina
		{439, lahaina_specific}, // lahainap
		{456, lahaina_specific}, // lahaina-atp
		{501, lahaina_specific},
		{502, lahaina_specific},
		{450, shima_specific}, // shima
		{457, waipio_specific}, //Waipio
		{482, waipio_specific}, //Waipio
		{552, waipio_specific}, //Waipio-LTE
		{506, diwali_specific}, //diwali
		{530, waipio_specific}, // cape
		{531, waipio_specific}, // cape
		{540, waipio_specific}, // cape
		{519, kalama_specific}, //Kalama
		{536, kalama_specific}, //Kalamap
		{600, kalama_specific}, //Kalama_sg
		{601, kalama_specific}, //Kalamap_sg
		{557, pineapple_specific}, //Pineapple
		{577, pineapple_specific}, //Pineapplep
		{537, parrot_specific}, //Netrani mobile
		{583, parrot_specific}, //Netrani mobile without modem
		{613, parrot_specific}, //Netrani APQ
		{631, parrot_specific},
		{663, parrot_specific}, //Netrani pro
		{660, canoe_specific}, //Canoe
		{661, canoe_specific}, //Canoep
		{722, canoe_common}, //Alana
                {723, canoe_common}, //Alana APQ
                {743, canoe_common}, //Gaming SKU

		{669, vienna_specific}, //SW6100
		{670, vienna_specific}, //SW6100P
		{685, alor_specific}, //Molokai
		{727, alor_specific}, //Molokai APQ
		{555, hamoa_specific}, // Hamoa
	};

	const std::unordered_multimap<int, std::pair<int, std::vector<struct target_therm_cfg>>>
	msm_limit_profile_specific = {
		{618, std::make_pair(0, sun_profile0)},
		{618, std::make_pair(1, sun_profile1)},
		{639, std::make_pair(0, sun_profile0)},
		{639, std::make_pair(1, sun_profile1)},
	};

	std::vector<struct target_therm_cfg> add_target_config(
			int socID, int lp,
			std::vector<struct target_therm_cfg> conf)
	{
		std::vector<struct target_therm_cfg> targetConf;

		if (msm_soc_specific.find(socID) != msm_soc_specific.end()) {
			targetConf = (msm_soc_specific.find(socID))->second;

			conf.insert(conf.end(), targetConf.begin(),
						targetConf.end());
		}

		auto range = msm_limit_profile_specific.equal_range(socID);
		auto it = range.first;
		if (range.first != msm_limit_profile_specific.end()) {
			for (; it != range.second; ++it) {
				if (it->second.first != lp)
					continue;
				targetConf = it->second.second;
				conf.insert(conf.end(), targetConf.begin(),targetConf.end());
				break;
			}
		}

		return conf;
	}

	ThermalConfig::ThermalConfig():cmnInst()
	{
		std::unordered_map<int, std::vector<struct target_therm_cfg>>::const_iterator it;
		std::vector<struct target_therm_cfg>::iterator it_vec;
		bool bcl_defined = false;
		std::string soc_val;
		int ct = 0;
		bool read_ok = false;

		do {
			if (cmnInst.readFromFile(socIDPath, soc_val) <= 0) {
				LOG(ERROR) <<"soc ID fetch error";
				return;
			}
			try {
				soc_id = std::stoi(soc_val, nullptr, 0);
				read_ok = true;
			}
			catch (std::exception &err) {
				LOG(ERROR) <<"soc id stoi err:" << err.what()
					<< " buf:" << soc_val;
			}
			ct++;
		} while (!read_ok && ct < RETRY_CT);
		if (soc_id <= 0) {
			LOG(ERROR) << "Invalid soc ID: " << soc_id;
			return;
		}

		auto range = msm_limit_profile_specific.equal_range(soc_id);
		if (range.first != msm_limit_profile_specific.end()) {
			limitp = cmnInst.findLimitProfile();
			if (limitp < 0) {
				LOG(DEBUG) << "Invalid limit profile, defaulting to 0.";
				limitp = 0;
			}
		}

		it = msm_soc_map.find(soc_id);
		if (it == msm_soc_map.end()) {
			LOG(ERROR) << "No config for soc ID: " << soc_id;
			return;
		}
		thermalConfig = add_target_config(soc_id, limitp, it->second);
		for (it_vec = thermalConfig.begin();
				it_vec != thermalConfig.end(); it_vec++) {
			if (it_vec->type == TemperatureType::BCL_PERCENTAGE)
				bcl_defined = true;
		}

		thermalConfig.push_back(bat_conf);
		if (!bcl_defined)
			thermalConfig.insert(thermalConfig.end(),
				bcl_conf.begin(), bcl_conf.end());
		LOG(DEBUG) << "Total sensors:" << thermalConfig.size();
	}

}  // namespace thermal
}  // namespace hardware
}  // namespace android
}  // namespace aidl


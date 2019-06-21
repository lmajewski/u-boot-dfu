// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2019
 * Lukasz Majewski, DENX Software Engineering, lukma@denx.de
 */

#include <common.h>
#include <dm.h>
#include <clk.h>
#include <asm/clk.h>

#include "clk.h"

struct sandbox_clk_test {
	struct clk clks[SANDBOX_CLK_TEST_ID_COUNT];
	struct clk_bulk bulk;
};

static const struct udevice_id sandbox_clk_ccf_test_ids[] = {
	{ .compatible = "sandbox,clk-ccf-test" },
	{ }
};

static int sandbox_clk_ccf_probe(struct udevice *dev)
{
	void *base = NULL;

	printf("%s: PROBE!\n", __func__);
#if 0
	clk_dm(IMX6QDL_CLK_PLL2,
	       imx_clk_pllv3(IMX_PLLV3_GENERIC, "pll2_bus", "osc",
			     base + 0x30, 0x1));

	clk_dm(IMX6QDL_CLK_PLL3_60M,
	       imx_clk_fixed_factor("pll3_60m",  "pll3_usb_otg",   1, 8));

	clk_dm(IMX6QDL_CLK_ECSPI_ROOT,
	       imx_clk_divider("ecspi_root", "pll3_60m", base + 0x38, 19, 6));

	clk_dm(IMX6QDL_CLK_ECSPI1,
	       imx_clk_gate2("ecspi1", "ecspi_root", base + 0x6c, 0));
#endif

	return 0;
}

U_BOOT_DRIVER(sandbox_clk_ccf_test) = {
	.name = "sandbox_clk_ccf_test",
	.id = UCLASS_CLK,
	.probe = sandbox_clk_ccf_probe,
	.of_match = sandbox_clk_ccf_test_ids,
	.priv_auto_alloc_size = sizeof(struct sandbox_clk_test),
};

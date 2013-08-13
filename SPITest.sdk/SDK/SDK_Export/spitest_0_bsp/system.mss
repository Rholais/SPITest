
 PARAMETER VERSION = 2.2.0


BEGIN OS
 PARAMETER OS_NAME = standalone
 PARAMETER OS_VER = 3.10.a
 PARAMETER PROC_INSTANCE = ps7_cortexa9_0
 PARAMETER STDIN = ps7_uart_1
 PARAMETER STDOUT = ps7_uart_1
END


BEGIN PROCESSOR
 PARAMETER DRIVER_NAME = cpu_cortexa9
 PARAMETER DRIVER_VER = 1.01.a
 PARAMETER HW_INSTANCE = ps7_cortexa9_0
END


BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 3.01.a
 PARAMETER HW_INSTANCE = axi_gpio_oled_dc
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 3.01.a
 PARAMETER HW_INSTANCE = axi_gpio_oled_res
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = spi
 PARAMETER DRIVER_VER = 3.05.a
 PARAMETER HW_INSTANCE = axi_spi_oled
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ps7_afi_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ps7_afi_1
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ps7_afi_2
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ps7_afi_3
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ps7_ddr_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ps7_ddrc_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = devcfg
 PARAMETER DRIVER_VER = 2.03.a
 PARAMETER HW_INSTANCE = ps7_dev_cfg_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = dmaps
 PARAMETER DRIVER_VER = 1.05.a
 PARAMETER HW_INSTANCE = ps7_dma_ns
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = dmaps
 PARAMETER DRIVER_VER = 1.05.a
 PARAMETER HW_INSTANCE = ps7_dma_s
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = emacps
 PARAMETER DRIVER_VER = 1.04.a
 PARAMETER HW_INSTANCE = ps7_ethernet_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpiops
 PARAMETER DRIVER_VER = 1.01.a
 PARAMETER HW_INSTANCE = ps7_gpio_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ps7_iop_bus_config_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = qspips
 PARAMETER DRIVER_VER = 2.02.a
 PARAMETER HW_INSTANCE = ps7_qspi_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ps7_qspi_linear_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ps7_ram_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ps7_ram_1
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = scugic
 PARAMETER DRIVER_VER = 1.04.a
 PARAMETER HW_INSTANCE = ps7_scugic_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = scutimer
 PARAMETER DRIVER_VER = 1.02.a
 PARAMETER HW_INSTANCE = ps7_scutimer_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = scuwdt
 PARAMETER DRIVER_VER = 1.02.a
 PARAMETER HW_INSTANCE = ps7_scuwdt_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ps7_sd_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ps7_slcr_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = ttcps
 PARAMETER DRIVER_VER = 1.01.a
 PARAMETER HW_INSTANCE = ps7_ttc_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = uartps
 PARAMETER DRIVER_VER = 1.04.a
 PARAMETER HW_INSTANCE = ps7_uart_1
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = usbps
 PARAMETER DRIVER_VER = 1.04.a
 PARAMETER HW_INSTANCE = ps7_usb_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 3.01.a
 PARAMETER HW_INSTANCE = axi_gpio_oled_vbat
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 3.01.a
 PARAMETER HW_INSTANCE = axi_gpio_oled_vdd
END



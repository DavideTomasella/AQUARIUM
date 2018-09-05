deps_config := \
	/home/davide/Documents/esp/esp-idf/components/app_trace/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/aws_iot/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/bt/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/esp32/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/ethernet/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/fatfs/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/freertos/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/heap/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/libsodium/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/log/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/lwip/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/mbedtls/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/openssl/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/pthread/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/spi_flash/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/spiffs/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/wear_levelling/Kconfig \
	/home/davide/Documents/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/davide/Documents/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/davide/Documents/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/davide/Documents/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;

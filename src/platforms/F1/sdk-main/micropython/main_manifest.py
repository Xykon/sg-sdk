freeze("$(PORT_DIR)/modules", "flashbdev.py")
include("$(MPY_DIR)/extmod/uasyncio")
freeze(".", "_boot.py")
freeze(".", "_inisetup.py")

# Require some micropython-lib modules.
require("dht")
require("ds18x20")
require("mip")
require("neopixel")
require("ntptime")
require("onewire")
require("umqtt.robust")
require("umqtt.simple")
require("upysh")
require("urequests")
require("webrepl")

FERRET = java -jar ~/dev/esp8266/muda/bin/ferret.jar
ARDUINO = arduino --board $(BOARD) --port $(PORT)

.PHONY: upload
upload: *.ino
	$(ARDUINO) --upload main.ino

.PHONY: verify
verify: *.ino
	$(ARDUINO) --verify main.ino

.PHONY: clean All

All:
	@echo "----------Building project:[ BridgeOfKonigsberg - Debug ]----------"
	@cd "BridgeOfKonigsberg" && "$(MAKE)" -f  "BridgeOfKonigsberg.mk"
clean:
	@echo "----------Cleaning project:[ BridgeOfKonigsberg - Debug ]----------"
	@cd "BridgeOfKonigsberg" && "$(MAKE)" -f  "BridgeOfKonigsberg.mk" clean

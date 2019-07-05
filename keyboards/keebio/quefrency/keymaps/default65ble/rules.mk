MCU = atmega32u4
F_CPU = 16000000 # Default
# F_CPU = 8000000 # https://www.reddit.com/r/MechanicalKeyboards/comments/7eiiht/guide_i_built_a_bluetooth_enabled_magicforce68_no/

### Bootloader information grabbed from Levinson notes
# Example of flashing this keyboard with Pro micro:
#     make levinson/rev2:default:avrdude
# Example of flashing this keyboard with Elite-C:
# You'll need to add `BOOTLOADER = atmel-dfu` to your `rules.mk` to ensure that resetting the board works properly.
# Hold the reset button on the Elite-C board, or the reset button on the keyboard if already assembled, then release the button and run:
#     make levinson/rev2:default:dfu
# # # Bootloader selection
# # #   Teensy       halfkay
# # #   Pro Micro    caterina
# # #   Atmel DFU    atmel-dfu - NEEDED FOR ELITE-C
# # #   LUFA DFU     lufa-dfu
# # #   QMK DFU      qmk-dfu
# # #   atmega32a    bootloadHID

BOOTLOADER = caterina # ProMicro
# BOOTLOADER = atmel-dfu # ELITE-C

# https://www.reddit.com/r/MechanicalKeyboards/comments/7eiiht/guide_i_built_a_bluetooth_enabled_magicforce68_no/
BLUETOOTH = AdafruitBLE # Enable BLE

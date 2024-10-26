#include <reg51.h>

void main() {
    unsigned char port1_val;  // Variable to hold the values of Port 1
    unsigned char prev_port1_val = 0x00;  // To store the previous state of Port 1
    P0 = 0x00;  // Set all pins of Port 0 to low initially
    P1 = 0xFF;  // Set all pins of Port 1 to input (high impedance)

    while (1) {
        port1_val = P1;  // Read the current state of Port 1

        // Check each bit in Port 1 to see if it has gone high
        for (int i = 0; i < 8; i++) {
            if ((port1_val & (1 << i)) && !(prev_port1_val & (1 << i))) {
                // Toggle the corresponding bit in Port 0
                P0 ^= (1 << i);
            }
        }

        // Update previous state
        prev_port1_val = port1_val;
    }
}

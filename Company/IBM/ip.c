#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void convertToIpv6(char* ipv4address) {
    char *octets[4];
    char *token;
    int i = 0;

    // Tokenize the IPv4 address into octets
    token = strtok(ipv4address, ".");
    while (token != NULL && i < 4) {
        octets[i++] = token;
        token = strtok(NULL, ".");
    }

    // Ensure we have exactly 4 octets
    if (i != 4) {
        printf("Invalid input\n");
        return;
    }

    // Check if it's the localhost address
    if (strcmp(octets[0], "127") == 0) {
        printf("::1\n");
        return;
    }

    // Prepare IPv6-mapped IPv4 address
    char ipv6[40] = "::FFFF:";  

    // Concatenate hex values of octets
    for (i = 0; i < 4; i++) {
        int octet = atoi(octets[i]);
        if (octet < 0 || octet > 255) {
            printf("Invalid input\n");
            return;
        }

        char hex[5];  // To store the hex representation (with a colon for formatting)
        if (i < 2) {
            // First two octets go together (XX:XX:)
            snprintf(hex, sizeof(hex), "%02X", octet);
            strncat(ipv6, hex, sizeof(ipv6) - strlen(ipv6) - 1);
        } else {
            // Last two octets (combine after a colon)
            if (i == 2) strcat(ipv6, ":");  // Add colon before third octet
            snprintf(hex, sizeof(hex), "%02X", octet);
            strncat(ipv6, hex, sizeof(ipv6) - strlen(ipv6) - 1);
        }
    }

    // Output the IPv6 address
    printf("%s\n", ipv6);
}

int main() {
    char ipv4address[16] = "192.168.10.92";
    convertToIpv6(ipv4address);
    return 0;
}

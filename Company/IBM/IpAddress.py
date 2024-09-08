def convertToIpv6(ipv4address):
  octets = ipv4address.split('.')

  if len(octets) != 4:
    return None

  hex_octets = [f"{int(octet):02x}" for octet in octets]
  ipv6address = f"::FFFF:{':'.join(hex_octets)}"

  return ipv6address

if __name__ == "__main__":
  ipv4address = input()
  ipv6address = convertToIpv6(ipv4address)

  if ipv6address:
    print(ipv6address)
  else:
    print("Invalid input")
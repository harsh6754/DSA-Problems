#include<bits/stdc++.h>
using namespace std;

string validateIP(const string& ip){
  regex ipv4_regex(R"(^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$)");
    regex ipv6_regex(R"(^(([A-Fa-f0-9]{1,4}:){7}[A-Fa-f0-9]{1,4}|::(?:[A-Fa-f0-9]{1,4}:){0,6}[A-Fa-f0-9]{1,4}|(?:[A-Fa-f0-9]{1,4}:){1,7}::[A-Fa-f0-9]{1,4}|(?:[A-Fa-f0-9]{1,4}:){1,6}:[A-Fa-f0-9]{1,4}|(?:[A-Fa-f0-9]{1,4}:){1,5}(?::[A-Fa-f0-9]{1,4}){1,2}|(?:[A-Fa-f0-9]{1,4}:){1,4}(?::[A-Fa-f0-9]{1,4}){1,3}|(?:[A-Fa-f0-9]{1,4}:){1,3}(?::[A-Fa-f0-9]{1,4}){1,4}|(?:[A-Fa-f0-9]{1,4}:){1,2}(?::[A-Fa-f0-9]{1,4}){1,5}|[A-Fa-f0-9]{1,4}:(?:(?::[A-Fa-f0-9]{1,4}){1,6})?::|::(?:(?::[A-Fa-f0-9]{1,4}){1,7}|:)|(?:::)?(?::[A-Fa-f0-9]{1,4}){1,7}|(?:::)?(?::[A-Fa-f0-9]{1,4}){1,6}|(?:::)?(?::[A-Fa-f0-9]{1,4}){1,5}|(?:::)?(?::[A-Fa-f0-9]{1,4}){1,4}|(?:::)?(?::[A-Fa-f0-9]{1,4}){1,3}|(?:::)?(?::[A-Fa-f0-9]{1,4}){1,2}|(?:::)?(?::[A-Fa-f0-9]{1,4})?::|(?:::)?::)$)");
    regex ipv4_mapped_ipv6_regex(R"(^::FFFF:((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$)");

    if (regex_match(ip, ipv4_regex)) {
        return "Valid IPv4 address";
    } else if (regex_match(ip, ipv6_regex)) {
        return "Valid IPv6 address";
    } else if (regex_match(ip, ipv4_mapped_ipv6_regex)) {
        return "Valid IPv4-mapped IPv6 address";
    } else {
        return "Invalid IP address";
    }
}

int main(){
  string ip;
  cin>>ip;
  cout<<validateIP(ip)<<endl;
}
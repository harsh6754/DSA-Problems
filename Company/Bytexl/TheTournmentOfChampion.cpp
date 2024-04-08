#include <iostream>

int simulate_training(int Xena_strength, int Ragnar_strength, int Galahad_strength, int Xena_intensity, int Ragnar_intensity, int Galahad_intensity) {
    int sessions = 0;
    while (Xena_strength != Ragnar_strength || Ragnar_strength != Galahad_strength) {
        Xena_strength += Xena_intensity;
        Ragnar_strength += Ragnar_intensity;
        Galahad_strength += Galahad_intensity;
        sessions++;
        
        // Check if strengths diverge infinitely
        if (sessions > 1000) {
            return -1;
        }
    }
    return sessions;
}

int main() {
    int Xena_strength, Ragnar_strength, Galahad_strength, Xena_intensity, Ragnar_intensity, Galahad_intensity;
    
    // Read input values
    std::cin >> Xena_strength >> Ragnar_strength >> Galahad_strength >> Xena_intensity >> Ragnar_intensity >> Galahad_intensity;
    
    // Call the function and print the result
    int sessions_needed = simulate_training(Xena_strength, Ragnar_strength, Galahad_strength, Xena_intensity, Ragnar_intensity, Galahad_intensity);
    std::cout << sessions_needed << std::endl;
    
    return 0;
}

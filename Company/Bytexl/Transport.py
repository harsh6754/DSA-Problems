def training_sessions():
    Xena_strength, Ragnar_strength, Galahad_strength = map(int, input().split())
    Xena_intensity, Ragnar_intensity, Galahad_intensity = map(int, input().split())

    sessions = 0
    while Xena_strength!= Ragnar_strength or Xena_strength!= Galahad_strength:
        sessions += 1
        Xena_growth = Xena_intensity
        Ragnar_growth = Ragnar_intensity
        Galahad_growth = Galahad_intensity

        Xena_strength += Xena_growth
        Ragnar_strength = max(Ragnar_strength + Ragnar_growth, 10**7)
        Galahad_strength += Galahad_growth

        if Ragnar_strength == 10**7 and Xena_strength!= Galahad_strength:
            return -1

    return sessions

sessions = training_sessions()
print(sessions)
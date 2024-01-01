def calculate_run_rate(total_balls, total_runs, runs_scored, balls_bowled):
     
    total_overs = total_balls // 6
    overs_finished = balls_bowled // 6 + (balls_bowled % 6) / 10
    current_run_rate = runs_scored / overs_finished
    total_run_rate = total_runs / total_overs
    eligibility = "Eligible to Win" if current_run_rate >= total_run_rate else "Not Eligible to Win"
 
    print(total_overs)
    print(f"{int(overs_finished)}.{int((overs_finished * 10) % 10)}")
    print(f"{current_run_rate:.1f}")
    print(f"{total_run_rate:.1f}")
    print(eligibility)

    total_balls = int(input())
    total_runs = int(input())
    total_runs = int(input())
    balls_bowled = int(input())

calculate_run_rate()


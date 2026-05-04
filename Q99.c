def car_fleet(target, position, speed):
    # Step 1: Pair and sort by position descending
    cars = sorted(zip(position, speed), reverse=True)

    fleets = 0
    max_time = 0

    # Step 2: Traverse cars
    for pos, spd in cars:
        time = (target - pos) / spd

        # If this car can't catch up → new fleet
        if time > max_time:
            fleets += 1
            max_time = time

    return fleets


# Example
target = 12
position = [10, 8, 0, 5, 3]
speed = [2, 4, 1, 1, 3]

print(car_fleet(target, position, speed))

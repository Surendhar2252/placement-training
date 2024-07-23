def min_cost_to_cut_board(cost_y, cost_x):
    cost_y.sort(reverse=True)
    cost_x.sort(reverse=True)
    h_cuts = v_cuts = 1
    total_cost = 0

    while cost_y or cost_x:
        if not cost_x or (cost_y and cost_y[0] >= cost_x[0]):
            total_cost += cost_y.pop(0) * v_cuts
            h_cuts += 1
        else:
            total_cost += cost_x.pop(0) * h_cuts
            v_cuts += 1

    return total_cost

print(min_cost_to_cut_board([2, 1, 3, 1, 4], [4, 1, 2]))

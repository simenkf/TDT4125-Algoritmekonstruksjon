from sys import argv

def read_instance(f):
    nb_elements, nb_sets = [int(x) for x in f.readline().split()]
    sets = []
    weights = []

    for line in f:
        tokens = line.split()
        weight = float(tokens[0])
        elements = [int(x)-1 for x in tokens[1:]]
        weights.append(weight)
        sets.append(elements)

    return sets, weights, nb_elements

def read_solution(f):
    return [bool(int(x)) for x in f]

def calculate_cost(solution, instance):
    if len(solution) != len(instance[0]):
        raise AssertionError('Wrong dimension on solution')
    covered = set()
    cost = 0
    for j in range(len(solution)):
        if solution[j]:
            covered |= set(instance[0][j])
            cost += instance[1][j]
    
    if covered == set(range(instance[2])):
        return cost
    else:
        return -1


def main():
    instance = None
    solution = None
    with open(argv[1]) as instance_f:
        instance = read_instance(instance_f)
    with open(argv[2]) as solution_f:
        solution = read_solution(solution_f)
    
    cost = calculate_cost(solution, instance)
    if cost == -1:
        print('Infeasible solution!')
    else:
        print('Cost:', cost)

if __name__ == '__main__':
    main()
k, m, n = map(int, input().split())

population = k + m + n
prob_homozygous_dominant = k / population
prob_homozygous_recessive = n / population
prob_heterozygous = m / population

prob_dominant = (4(k*(k-1) + 2*k*m+2*k*n+m*n) + 3*m*(m-1))/(4*population*(population-1))


print(prob_dominant)

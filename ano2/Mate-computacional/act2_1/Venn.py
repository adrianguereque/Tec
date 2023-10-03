def common_elements(arr1, arr2):
    return list(set(arr1) & set(arr2))

def unique_elements(arr1, arr2):
    return list(set(arr1) - set(arr2))

E18_29 = ["mezclas","azul","morado","rosa","reloj de arena",
          "grande","mediano","cilindro inclinado"]
E30_59 = ["mezclas","verde","rosa","negro","azul","morado",
          "cilindro inclinado","grande","mediano","bombilla"]
E60 = ["margarita","morado","rosa","reloj de arena","mediano",
       "verde","bombilla"]

common_e18_e30 = common_elements(E18_29, E30_59)
common_e18_e60 = common_elements(E18_29, E60)
common_e30_e60 = common_elements(E30_59, E60)
common_all = common_elements(common_e18_e30, common_e18_e60)

unique_e18 = unique_elements(E18_29, E30_59 + E60)
unique_e30 = unique_elements(E30_59, E18_29 + E60)
unique_e60 = unique_elements(E60, E18_29 + E30_59)

print("Common between E18_29 and E30_59:", common_e18_e30)
print("Common between E18_29 and E60:", common_e18_e60)
print("Common between E30_59 and E60:", common_e30_e60)
print("Common between all:", common_all)

print("Unique to E18_29:", unique_e18)
print("Unique to E30_59:", unique_e30)
print("Unique to E60:", unique_e60)

all_elements = E18_29 + E30_59 + E60
unique_elements_count = len(set(all_elements))

print("Number of unique elements without repetitions:", unique_elements_count)
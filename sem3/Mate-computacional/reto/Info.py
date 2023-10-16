import pandas as pd
from matplotlib_venn import venn3
import matplotlib.pyplot as plt

# Replace 'your_excel_file.xlsx' with the actual path to your Excel file
excel_file_path = './TipoDeEnvase.xlsx'

# Read the Excel file into a DataFrame
df = pd.read_excel(excel_file_path)

# Separate data into age groups
df_18_29 = df[df['¿Qué edad tiene?'] == '18 a 29 años']
df_30_59 = df[df['¿Qué edad tiene?'] == '30 a 59 años']
df_60_above = df[df['¿Qué edad tiene?'] == '60 en adelante']

# Extract sets of unique responses for each age group
set_18_29 = set(df_18_29['¿Cuál es su material preferido para su envase?'])
set_30_59 = set(df_30_59['¿Cuál es su material preferido para su envase?'])
set_60_above = set(df_60_above['¿Cuál es su material preferido para su envase?'])

# Create Venn diagram
venn = venn3([set_18_29, set_30_59, set_60_above], ('18-29', '30-59', '60+'))

# Add labels
venn.get_label_by_id('100').set_text(len(set_18_29))
venn.get_label_by_id('010').set_text(len(set_30_59))
venn.get_label_by_id('001').set_text(len(set_60_above))
venn.get_label_by_id('110').set_text(len(set_18_29 & set_30_59))
venn.get_label_by_id('101').set_text(len(set_18_29 & set_60_above))
venn.get_label_by_id('011').set_text(len(set_30_59 & set_60_above))
venn.get_label_by_id('111').set_text(len(set_18_29 & set_30_59 & set_60_above))

# Display the Venn diagram
plt.show()

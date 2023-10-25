import pandas as pd
import numpy as np
from sklearn.metrics import roc_auc_score

# Parse the csv data
data = pd.read_csv("data.csv")
data_longformer = pd.read_csv("Base.csv")

out = roc_auc_score(data["label"], data["Zero Gpt"])
out_longformer = roc_auc_score(data_longformer["label"], data_longformer["base"])


print("The AUROC Score using longformer model for predictions :", out_longformer)
print("The AUROC Score using ZeroGPT model for predictions :", out)

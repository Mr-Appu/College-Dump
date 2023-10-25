# Deepfake Text Detection

- Project Report  : https://drive.google.com/file/d/1wDfB9cSq6LlFFYl-mdYJa3ybpP1FQpIW/view?usp=sharing
- Dataset         : https://drive.google.com/drive/folders/1p09vDiEvoA-ZPmpqkB2WApcwMQWiiMRl
- Model           : https://drive.google.com/drive/folders/1_c7VDD_SWdPbyHvdOgUqYvvdUKCMTMYh?usp=sharing 

## Results
|Testbeds|Classifier Model|AUROC|
|--------|----------------|-----|
|Unseen Domains & Unseen Model| Longformer (Base Model) |94%|
|Unseen Domains & Unseen Model[^1]| Longformer |77%|
|Unseen Domains & Unseen Model[^1]| ZeroGPT |**92%**|

[^1]:The data used for prediction is sampled  (stratified sampling )  from the wilder [testbeds](https://drive.google.com/drive/folders/1p09vDiEvoA-ZPmpqkB2WApcwMQWiiMRl) dataset.

### References

- **(Original Paper)** Li, Y., Li, Q., Cui, L., Bi, W., Wang, L., Yang, L., Shi, S., & Zhang, Y. (2023). Deepfake Text Detection in the Wild. ArXiv. /abs/2305.13242
- Mitchell, E., Lee, Y., Khazatsky, A., Manning, C. D., & Finn, C. (2023). DetectGPT: Zero-Shot Machine-Generated Text Detection using Probability Curvature. ArXiv. /abs/2301.11305
- Verma, V., Fleisig, E., Tomlin, N., & Klein, D. (2023). Ghostbuster: Detecting Text Ghostwritten by Large Language Models. ArXiv. /abs/2305.15047

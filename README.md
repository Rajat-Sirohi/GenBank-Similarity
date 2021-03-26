# GenBank Intraspecies Similarity Analysis

This program utilizes genome sequencing data for *Synechococcus elongatus* from [GenBank](https://www.ncbi.nlm.nih.gov/genbank) in order to devise a computational measure for expected intraspecies genomic similarity.

I used an element-wise comparison of the genome strands as the similarity measure, which generates the following probability distribution for two random genomes consisting of 2940 nucleotides (probability vs. similarity):

![alt text](Images/probability_distribution.png?raw=true)

After analyzing 100 samples of the bacteria's genomes, consisting of 4950 comparisons, I generated the following histogram for my sampling distribution (frequency vs. similarity and z-score, respectively):

![alt text](Images/histogram_similarity.png?raw=true)
![alt text](Images/histogram_z-scores.png?raw=true)

These results suggest that a z-score of approximately 91.380 is to be expected as a measure of intraspecies genomic similarity. There are several possible avenues of further research, including more sophisticated measures of similarity (e.g. cosine similarity, pair-wise nucleotide comparison, weighted comparisons) as well as setting more realistic limitations on viable genomes.

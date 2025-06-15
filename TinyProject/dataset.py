from ucimlrepo import fetch_ucirepo

# Fetch dataset
computer_hardware = fetch_ucirepo(id=29)

# Data
X = computer_hardware.data.features

# Save to CSV
X.to_csv("data.csv", index=False)

print("Features saved to data.csv")

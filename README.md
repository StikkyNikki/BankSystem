Software Requirements Specification (SRS)
1. Introduction
1.1 Purpose
The purpose of the program is to simulate a bank system that handles multiple clients simultaneously. The client will be able to withdraw, deposit and check balance.
1.2 Scope
The purpose is to simulate several statements from the banking system at the same time, using multithreading.

2. Overall Description
2.1 Product Functions
The product shall allow the simulated client to withdraw and deposit money into an associated bank account. Furthermore, it shall allow the user to view the bank balance of their associated bank account.
The system shall allow multiple clients to access its services at the same time.
The system shall ensure that the information is secure and reliable through the usage of measures of a multitude of security measures. 

3. Specific Requirements  
3.1 Functional Requirements
- The system must use multithreading to simulate concurrent customers and synchronization techniques to ensure the integrity of shared resources.
- The client will be able to check it’s balance.
- The client will be able to withdraw money from it’s account.
- The client will be able to deposit money from it’s account. 
- Print the account balances after all customers have completed their transactions.
- Each client will perform random transactions (deposits or withdrawals).
- The system will use methods to add accounts and retrieve account details.

3.2 Non-functional Requirements
Performance: The system should allow and be able to handle at minimum five accounts and ten clients. 
Security: The system should secure the shared data points in the system by using measures such as mutex. 
Reliability: The system should reliably be able to handle multiple client actions without dropping the input or cause any major issues with the data. 


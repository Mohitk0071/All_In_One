import numpy as np 
import pandas as pd
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score,confusion_matrix,classification_report

data=pd.read_csv("insurance_data.csv")
X=data[['age']]
Y=data['bought_insurance']
X_train,X_test,Y_train,Y_test=  train_test_split(X,Y,test_size=0.3,random_state=42)
model=LogisticRegression()
model.fit(X_train,Y_train)
Y_pred=model.predict(X_test)
Y_prob=model.predict_proba(X_test)
print("coeffiecient(B1):",model.coef_)
print("intercept(B0):",model.intercept_)
print("Predictions:",Y_pred)
print("Probabilities:",Y_prob)
print("Accuracy:",accuracy_score(Y_test,Y_pred))
print("Confusion Matrix:\n",confusion_matrix(Y_test,Y_pred))

new_student=np.array([[6.5]])
prediction=model.predict(new_student)
probability=model.predict_proba(new_student)
print(f"/n Prediction for 6.5 hours studied:{'pass' if prediction==1  else 'Fail'}")
print(f"probability of passing:{probability[0][1]:.2f}")



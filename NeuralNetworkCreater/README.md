This directory is for training and evaluating MobileNetv2 models! Please feel to use this code to generate your own models for your personal use, we will provide instructions here and comments on the code to highlight how to alter the code for your own personal use.

Heading- Prerequisites 
To use our code to make your own personal models, you're going to need to install some packages in able to run this code. These packages are required to be downloaded onto your device in order to run the python code. 

The required prerequisites for this code are: TensorFlow, pandas, numpy, matplotlib, keras, sklearn, seaborn and OpenCV. All these can be installed with pip3.

Heading-Datasets
To train a Neural Network model data must be aquired. This allows the model, in gymBuddi's case, to learn the excersise pose's gymBuddi needs. A great way to train your models is to use premade data sets on the website Kaggle. Kaggle is full of datasets for thousands of different things so best to start there when finding your data!

The Kaggle data set gymBuddi used can be found using the following link: 
https://www.kaggle.com/datasets/ujjwalchowdhury/yoga-pose-classification

Download this dataset (or any other dataset you wish) and add it to directory within the project file called data. cd into this directory using the terminal on your device, then unzip the downloaded file and rename the file to data.zip.

TERMINAL WINDOW:
mv archive.zip data.zip 
unzip data.zip

If you're making your own dataset this is where things will change, so BEWARE!!!

2 folders will be created in the 'data' folder called SOMETHING_test and SOMETHING_train. Depending on what the 'SOMETHING' is called for your personal data set, you will need to alter the train.py code before training the model. Refer to the comment in the code on line 15 for the required change.

Heading-Training the Model 
The train.py script creates a mobileNetv2 model which is trained using Keras. Type the following command in your terminal to train your model!

TERMINAL WINDOW:
python3 train.py 

Dont worry if this is taking ages, that is expected! Perfect time to go get some gains and pump some iron!

Heading-Eporting the Model
To allow OpenCV to be compatible with the model must be converted into a format that OpenCV can read. To export the file into the protobuf format, run the export.py script using the following command on you're terminal.

TERMINAL WINDOW:
python3 export.py

Heading-Testing
To check your model is sucessful a great idea is to test it using a live camera stream. To carry out the test ensure your camera is connected and simply input this command into your terminal!

TERMINAL WINDOW:
python3 test-opencv-feed.py

gymBuddi hope this tutorial is easy to follow! Dont hessetate to contact us with any questions or issues experienced! Please share any models you've created with the gymBuddi team!

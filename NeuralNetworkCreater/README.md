<h1> Building a Neural Network </h1>
This directory is for training and evaluating MobileNetv2 models! Please feel to use this code to generate your own models for your personal use, we will provide instructions here and comments on the code to highlight how to alter the code for your own personal use.
<br>
<h2> Prerequisites </h2>
To use our code to make your own personal models, you're going to need to install some packages in able to run this code. These packages are required to be downloaded onto your device in order to run the python code. 
<br>
<br>
All the following packages can be installed with pip3.The required prerequisites for this code are: <br> <br>
<ul>
<li>TensorFlow
<li>pandas
<li>numpy
<li>matplotlib
<li>keras
<li>sklearn
<li>seaborn 
<li>OpenCV.
</ul> 
<h2> Datasets </h2>
To train a Neural Network model data must be aquired. This allows the model, in gymBuddi's case, to learn the excersise pose's gymBuddi needs. A great way to train your models is to use premade data sets on the website Kaggle. Kaggle is full of datasets for thousands of different things so best to start there when finding your data!
<br><br>
The Kaggle data set gymBuddi used can be found using the following link: 
https://www.kaggle.com/datasets/ujjwalchowdhury/yoga-pose-classification
<br><br>
Download this dataset (or any other dataset you wish) and add it to directory within the project file called data. cd into this directory using the terminal on your device, then unzip the downloaded file and rename the file to data.zip.
<br> <br>
TERMINAL WINDOW: <br>
mv archive.zip data.zip <br>
unzip data.zip
<br><br>
If you're making your own dataset this is where things will change, so BEWARE!!!
<br><br>
2 folders will be created in the 'data' folder called SOMETHING_test and SOMETHING_train. Depending on what the 'SOMETHING' is called for your personal data set, you will need to alter the train.py code before training the model. Refer to the comment in the code on line 15 for the required change.

<h2>Training the Model 💪 </h2>
The train.py script creates a mobileNetv2 model which is trained using Keras. Type the following command in your terminal to train your model!
<br><br>

TERMINAL WINDOW:<br>
python3 train.py <br>
<br><br>

Dont worry if this takes a while, that is expected! Perfect time to go get some gains and pump some iron!
<h2>Exporting the Model </h2>
To allow OpenCV to be compatible with the model must be converted into a format that OpenCV can read. To export the file into the protobuf format, run the export.py script using the following command on you're terminal.
<br><br>
TERMINAL WINDOW: <br>
python3 export.py <br>

<h2> Testing </h2>
To check your model is sucessful a great idea is to test it using a live camera stream. To carry out the test ensure your camera is connected and simply input this command into your terminal!
<br><br>
TERMINAL WINDOW: <br>
python3 test-opencv-feed.py <br> <br> 

gymBuddi hope this tutorial is easy to follow! Dont hessetate to contact us with any questions or issues experienced! Please share any models you've created with the gymBuddi team!

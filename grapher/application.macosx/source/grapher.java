import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class grapher extends PApplet {

// Made by Hayk Khachatryan
// UCL COMP101P coursework
// Using Processing to display readings from the light sensor on an Engduino as a live graph
// REMEMBER TO CHANGE SERIAL ADDRESS TO 0

int width = 1280;
int height = 600;
float[] graph = new float[width];
float buffer = 0;
String input = "";
Serial myPort;
int available = 0;


public void setup()
{
  printArray(Serial.list());
  try {
    myPort = new Serial(this, Serial.list()[1], 9600);
    available = 1;
  } catch (Exception e){
    textAlign(CENTER, CENTER);
    text("No device available at the default index of 0",width/2,height/2);
    available = 0;
  }
   
  frameRate(1000);
  for(int i = 0; i < width - 101; i++)
  {
    graph[i] = 560;
  }
  

  
}

public void draw()
{
  background(255,255,255);
  line(100,height - 40,width,height - 40);
  line(100,0,100,height - 40);
  fill(0);
  text("Time",width/2,height-20);
  int y = 10;
  int number = 1000;
    // y-axis labels and markers
  for (int i = 0; i < 11; i++)
  {
    line(95,y,100,y);
    textAlign(RIGHT);
    text(number,90,y + 5);
    y += 55;
    number -= 100;
  }
  input = myPort.readStringUntil('\n');
  // Checks to remove null input errors then maps the light sensor input values relative to the scale of the graph.
  if (available == 1 && input != null) {
    input = input.replace("\n","");
    buffer = map(Float.parseFloat(input),0,1000,550,0);
    println(buffer);
  }
 
  for(int i = 0; i < width - 101; i++)
  {
    graph[i] = graph[i+1];
  }
  
  graph[width-101] = buffer;
  
  for(int i = width - 101; i > 0; i--)
  {
    line(i+100,graph[i-1], i+102, graph[i]);
  }
}
  public void settings() {  size(1280,600); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "grapher" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}

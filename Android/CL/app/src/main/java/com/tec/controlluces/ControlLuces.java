package com.tec.controlluces;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;


public class ControlLuces extends AppCompatActivity {

    //Variables transmision de datos
    private String serverIpAddress = "";//Buscar como capturarlo desde usuario
    private Socket socket;
    private int PORT = 5555;//revisar si hay q cambiar
    private boolean addr = true;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        //Definicion de variables
        final Boolean[] isPressed = {false};
        final Button bL3, bL4, bL5, bL6, bL7;

        //Socket
        try{
            InetAddress serverAddr = InetAddress.getByName(serverIpAddress);
            socket = new Socket(serverAddr, PORT);
        }//Close try
        catch (UnknownHostException e) {
            e.printStackTrace();}//close Catch UnknownHost
        catch (IOException e) {
            e.printStackTrace();}//Close IOException

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_control_luces);

        final PrintWriter[] dout = new PrintWriter[1];//Variables necesarias
        final String[] data = {"L"};//para transmision

        //Boton Luz 3
        bL3 = (Button) findViewById(R.id.Luz3);
        bL3.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){ //led off
                    bL3.setBackgroundResource(R.drawable.led_red);
                    data[0] = "L3-0"; }//led off
                else{ //led on
                    bL3.setBackgroundResource(R.drawable.led_green);
                    data[0] = "L3-1"; }//led on
                isPressed[0] = !isPressed[0];

                //Envio datos
                try{
                    dout[0] = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
                    dout[0].println(data[0]);
                } catch (IOException e) {
                    e.printStackTrace();}
            }
        });//Close L3.setOnClickListener

        //Boton Luz 4
        bL4 = (Button) findViewById(R.id.Luz4);
        bL4.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){ //led off
                    bL4.setBackgroundResource(R.drawable.led_red);
                    data[0] = "L4-0"; }
                else{
                    //led on
                    bL4.setBackgroundResource(R.drawable.led_green);
                    data[0] = "L4-1"; }
                isPressed[0] = !isPressed[0];

                //Envio datos
                try{
                    dout[0] = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
                    dout[0].println(data[0]);
                } catch (IOException e) {
                    e.printStackTrace(); }
            }
        });//Close L4.setOnClickListener

        //Boton Luz 5
        bL5 = (Button) findViewById(R.id.Luz5);
        bL5.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){ //led off
                    bL5.setBackgroundResource(R.drawable.led_red);
                    data[0] = "L5-0"; }
                else{//led on
                    bL5.setBackgroundResource(R.drawable.led_green);
                    data[0] = "L5-1"; }
                isPressed[0] = !isPressed[0];

                //Envio datos
                try{
                    dout[0] = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
                    dout[0].println(data[0]);
                } catch (IOException e) {
                    e.printStackTrace(); }
            }
        });//Close L5.setOnClickListener

        //Boton Luz 6
        bL6 = (Button) findViewById(R.id.Luz6);
        bL6.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){
                    //led off
                    bL6.setBackgroundResource(R.drawable.led_red);
                    data[0] = "L6-0"; }
                else{//led on
                    bL6.setBackgroundResource(R.drawable.led_green);
                    data[0] = "L6-1";}
                isPressed[0] = !isPressed[0];

                //Envio datos
                try{
                    dout[0] = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
                    dout[0].println(data[0]);
                } catch (IOException e) {
                    e.printStackTrace();}
            }
        });//Close L6.setOnClickListener

        //Boton Luz 7
        bL7 = (Button) findViewById(R.id.Luz7);
        bL7.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){
                    //led off
                    bL7.setBackgroundResource(R.drawable.led_red);
                    data[0] = "L7-0";}
                else{
                    //led on
                    bL7.setBackgroundResource(R.drawable.led_green);
                    data[0] = "L7-1";}
                isPressed[0] = !isPressed[0];

                //Envio datos
                try{
                    dout[0] = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
                    dout[0].println(data[0]);
                } catch (IOException e) {
                    e.printStackTrace();}
            }
        });//Close L7.setOnClickListener

        //Envio datos
        try{
            dout[0] = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
            dout[0].println(data[0]);
        } catch (IOException e) {
            e.printStackTrace();}

    }//Close void onCreate

}//End Class
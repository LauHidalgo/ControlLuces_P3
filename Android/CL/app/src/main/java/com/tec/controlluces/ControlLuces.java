package com.tec.controlluces;

import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;
import java.net.UnknownHostException;


public class ControlLuces extends AppCompatActivity {

    //Creacion de variables
    Boolean[] isPressed = {false};
    Button bL3, bL4, bL5, bL6, bL7;
    EditText changeAddress,changePort;
    Button bConnect, bClear;
    TextView tResponse;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_control_luces);

        //Definicion de variables
        changeAddress = (EditText) findViewById(R.id.address);
        changePort = (EditText) findViewById(R.id.port);
        bConnect = (Button)findViewById(R.id.connect);
        bClear = (Button)findViewById(R.id.clear);
        tResponse = (TextView)findViewById(R.id.response);

        bConnect.setOnClickListener(bConnectOnClickListener);
        bClear.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tResponse.setText("");
            } });

        //Boton Luz 3
        bL3 = (Button) findViewById(R.id.Luz3);
        bL3.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){ //led off
                    bL3.setBackgroundResource(R.drawable.led_red);}
                else{ //led on
                    bL3.setBackgroundResource(R.drawable.led_green);}
                isPressed[0] = !isPressed[0];

                //Envio datos

            }
        });//Close L3.setOnClickListener

        //Boton Luz 4
        bL4 = (Button) findViewById(R.id.Luz4);
        bL4.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){ //led off
                    bL4.setBackgroundResource(R.drawable.led_red);
                    }
                else{
                    //led on
                    bL4.setBackgroundResource(R.drawable.led_green);
                    }
                isPressed[0] = !isPressed[0];
            }
        });//Close L4.setOnClickListener

        //Boton Luz 5
        bL5 = (Button) findViewById(R.id.Luz5);
        bL5.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){ //led off
                    bL5.setBackgroundResource(R.drawable.led_red);
                    }
                else{//led on
                    bL5.setBackgroundResource(R.drawable.led_green);
                    }
                isPressed[0] = !isPressed[0];
            }
        });//Close L5.setOnClickListener

        //Boton Luz 6
        bL6 = (Button) findViewById(R.id.Luz6);
        bL6.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){//led off
                    bL6.setBackgroundResource(R.drawable.led_red);
                    }
                else{//led on
                    bL6.setBackgroundResource(R.drawable.led_green);
                    }
                isPressed[0] = !isPressed[0];
            }
        });//Close L6.setOnClickListener

        //Boton Luz 7
        bL7 = (Button) findViewById(R.id.Luz7);
        bL7.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(isPressed[0]){//led off
                    bL7.setBackgroundResource(R.drawable.led_red);
                    }
                else{ //led on
                    bL7.setBackgroundResource(R.drawable.led_green);
                    }
                isPressed[0] = !isPressed[0];
            }
        });//Close L7.setOnClickListener

    }//Close void onCreate

    View.OnClickListener bConnectOnClickListener = new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            TaskClient myTaskClient = new TaskClient(changeAddress.getText().toString(), Integer.parseInt(changePort.getText().toString())) {
                @Override
                protected Void doInBackground(Void... params) {
                    Socket socket = null;

                    try{
                        socket = new Socket(destAdd,destPort);

                        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream(1024);
                        byte[] buffer = new byte[1024];
                        int bytesRead;
                        InputStream inputStream = socket.getInputStream();

                        while((bytesRead = inputStream.read(buffer))!= -1){
                            byteArrayOutputStream.write(buffer, 0, bytesRead);
                            resp += byteArrayOutputStream.toString("UTF-8");
                        }//Close while
                    }//Close try
                    catch (UnknownHostException e) {
                        e.printStackTrace();
                        resp = "UnknownHostException: " + e.toString();
                    } catch (IOException e) {
                        e.printStackTrace();
                        resp = "IOException: " + e.toString();
                    }finally {
                        if(socket != null){
                            try{
                                socket.close();
                            }//close try
                            catch (IOException e) {
                                e.printStackTrace(); }
                        }//Close if socket
                    }//Close finally
                    return null;
                }
            };
            myTaskClient.execute();
        }};//Close bConnectOnClickListener

    public abstract class TaskClient extends AsyncTask<Void, Void, Void>{
        String destAdd;
        int destPort;
        String resp ="";
        TaskClient(String addr, int port) {
            destAdd = addr;
            destPort = port;}//Close TaskClient


        protected void postExecute(Void result){
            tResponse.setText(resp);
            super.onPostExecute(result);}//Close postExecute

    }//Close TaskClient

}//End Class
package com.tec.controlluces;

import android.content.Intent;
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
    EditText changeAddress,changePort;
    Button bConnect, bClear, bContinue;
    TextView tResponse;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_control_luces);

        //Definicion de variables
        changeAddress = (EditText) findViewById(R.id.address);
        changePort = (EditText) findViewById(R.id.port);
        tResponse = (TextView)findViewById(R.id.response);
        bConnect = (Button)findViewById(R.id.connect);
        bClear = (Button)findViewById(R.id.clear);
        bContinue = (Button)findViewById(R.id.continuar);

        //setClickOnListener
        bConnect.setOnClickListener(bConnectOnClickListener);

        bClear.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tResponse.setText("");
                changeAddress.setText("");
                changePort.setText("");
            } });
        bContinue.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                Intent goButtons = new Intent(ControlLuces.this,buttons.class);
                startActivity(goButtons);
            }
        });

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
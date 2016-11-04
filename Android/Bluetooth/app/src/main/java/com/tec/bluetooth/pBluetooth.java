package com.tec.bluetooth;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Set;

public class pBluetooth extends AppCompatActivity {

    //Variables de status de conexion
    TextView tConnecStatus;
    ListView pariedListView;

    //Dispositivos
    private BluetoothAdapter bluetoothAdap;
    private ArrayAdapter<String> PairedDevicesArray;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_p_bluetooth);

        tConnecStatus = (TextView) findViewById(R.id.connecting);
        tConnecStatus.setTextSize(32);

        //Inicializacion array adaptadores
        pariedListView = new ArrayAdapter<String>(this; R.layout.device_name);

        //Encuentra y configura ListView de paired devices
        pariedListView = (ListView) findViewById(R.id.paired_devices);
        pariedListView.setAdapter(PairedDevicesArray);
    }//close onCreate

    public void onResume(){
        super.onResume();
        checkStateBT();
        PairedDevicesArray.clear();
        tConnecStatus.setText("");

        //obtiene Bluetooth
        bluetoothAdap = BluetoothAdapter.getDefaultAdapter();
        Set<BluetoothDevice> pairedDevices = bluetoothAdap.getBondedDevices();

        //Se agregan dispositivos enlazados previamente
        if(pairedDevices.size()>0){
            findViewById(R.id.title_paired_devices).setVisibility(View.VISIBLE);//se hace textView visible
            for(BluetoothDevice device : pairedDevices){
                PairedDevicesArray.add(device.getName() + "\n" + device.getAddress());
            }//Close for
        }//close if
        else{
            PairedDevicesArray.add("No dispositivos enlazados");
        }//close else
    }//Close onResume

    private void checkStateBT(){
        bluetoothAdap = BluetoothAdapter.getDefaultAdapter();
        if(bluetoothAdap==null){
            Toast.makeText(getBaseContext(), "El dispositivo no soporta conexion Bluetooth", Toast.LENGTH_SHORT).show();
            finish();;
        }//close if
        else{
            if(!bluetoothAdap.isEnabled()){
                Intent enableBlueInt = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
                startActivityForResult(enableBlueInt,1);
            }//close if bluetoothAdap.isEnabled()
        }//close else
    }//close checkStateBT

}//Close class

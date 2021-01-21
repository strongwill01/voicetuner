package cn.edu.voicetuner;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("VoiceTuner");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        VoiceTuner tuner = new VoiceTuner();

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
//        tv.setText(tuner.stringFromJNI() + " V" + tuner.getVersion());
    }


}

/**
 * error:
 * 1、warning: CMake Error: CMake can not determine linker language for target: **
 * resolve: 是CMakeLists.txt->add_library(......)里面的cpp文件路径找不到。
 */

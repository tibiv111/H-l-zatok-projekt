<ui version="4.0" >
 <class>ChatDialog</class>
 <widget class="QDialog" name="ChatDialog" >
  <property name="geometry" >
   <rect>
    <x>0</x>
    <y>0</y>
    <width>513</width>
    <height>349</height>
   </rect>
  </property>
  <property name="windowTitle" >
   <string>Chat</string>
  </property>
  <layout class="QVBoxLayout" >
   <property name="margin" >
    <number>9</number>
   </property>
   <property name="spacing" >
    <number>6</number>
   </property>
   <item>
    <layout class="QHBoxLayout" >
     <property name="margin" >
      <number>0</number>
     </property>
     <property name="spacing" >
      <number>6</number>
     </property>
     <item>
      <widget class="QTextEdit" name="textEdit" >
       <property name="focusPolicy" >
        <enum>Qt::NoFocus</enum>
       </property>
       <property name="readOnly" >
        <bool>true</bool>
       </property>
      </widget>
     </item>
     <item>
      <widget class="QListWidget" name="listWidget" >
       <property name="maximumSize" >
        <size>
         <width>180</width>
         <height>16777215</height>
        </size>
       </property>
       <property name="focusPolicy" >
        <enum>Qt::NoFocus</enum>
       </property>
      </widget>
     </item>
    </layout>
   </item>
   <item>
    <layout class="QHBoxLayout" >
     <property name="margin" >
      <number>0</number>
     </property>
     <property name="spacing" >
      <number>6</number>
     </property>
     <item>
      <widget class="QLabel" name="label" >
       <property name="text" >
        <string>Message:</string>
       </property>
      </widget>
     </item>
     <item>
      <widget class="QLineEdit" name="lineEdit" />
     </item>
    </layout>
   </item>
  </layout>
 </widget>
 <resources/>
 <connections/>
</ui>

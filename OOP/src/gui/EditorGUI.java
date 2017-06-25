package gui;

import javax.swing.*;
import java.awt.event.*;
import dictionaries.*;

public class EditorGUI implements Runnable {
	public JFrame frame;
	public JButton readButton;
	public JButton saveButton;
	public JButton syncButton;

	public void run(){
		frame = new JFrame();
		readButton = new JButton("nuskaityti");
		readButton.setBounds(0, 0, 150, 300);
		readButton.addActionListener(new ReadListener());
		saveButton = new JButton("irasyti");
		saveButton.setBounds(150, 0, 150, 300);
		saveButton.addActionListener(new SaveListener());
		syncButton = new JButton("Sync");
		syncButton.setBounds(300, 0, 150, 300);
		syncButton.addActionListener(new SyncListener());
		frame.getContentPane().setLayout(null);
		frame.getContentPane().add(saveButton);
		frame.getContentPane().add(readButton);
		frame.getContentPane().add(syncButton);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(450, 300);
		frame.setVisible(true);
	}

	public class SyncListener implements ActionListener {
		public PredictionDictionary dict = new PredictionDictionary();

		public void actionPerformed(ActionEvent event){
			Runnable sync = new DictionarySync(dict);
			
			for(int i = 0; i < 10; i++){
				Thread thread = new Thread(sync);
				thread.start();
			}

			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
			DictionarySync a = (DictionarySync) sync;
			dict = a.dict;
			System.out.println(dict.avaiblePredictions);

		}
	}

	public class ReadListener implements ActionListener {
		public Dictionary dict;

		public void actionPerformed(ActionEvent event){
			Runnable read = new DictionaryReader();
			Thread thread = new Thread(read);
			thread.start();
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			DictionaryReader a = (DictionaryReader) read;
			Dictionary dictNew = a.dict;
			dict = dictNew;
			PredictionDictionary preDict = (PredictionDictionary) dict;
		}
	}

	public class SaveListener implements ActionListener {
		public PredictionDictionary dict = new PredictionDictionary();

		public void actionPerformed(ActionEvent event){
			Runnable save = new DictionarySaver(dict);
			Thread thread = new Thread(save);
			thread.start();
		}
	}
}


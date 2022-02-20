package telecommande_swing;

import javax.swing.*;

import java.awt.BorderLayout;
import java.awt.event.*;

public class Telecommande extends JFrame {
	
	private static final long serialVersionUID = 1L;

	JTextArea text;
	JButton button1;
	JButton button2;
	JButton button3;
	
	AbstractAction action1;
	AbstractAction action2;
	AbstractAction action3;
	
	public static void main(String[] args) {
		new Telecommande();
	}
	
	public Telecommande() {
		button1 = new JButton("Bonnie");
		button2 = new JButton("Clyde");
		button3 = new JButton("Close");
		
		text = new JTextArea(10, 30);
		JScrollPane scroll = new JScrollPane(text);
		add(scroll, BorderLayout.CENTER);
		
		JPanel buttonPanel = new JPanel();
		JMenuBar menus = new JMenuBar();
		JMenu menuD = new JMenu("Menu");
		JToolBar barre = new JToolBar();
		
		barre.add(new ActionBonnie("Bonnie"));
		barre.add(new ActionClyde("Clyde"));
		barre.add(new ActionClose("Close"));
		
		menuD.add(new ActionBonnie("Bonnie"));
		menuD.add(new ActionClyde("Clyde"));
		menuD.add(new ActionClose("Close"));
		
		menus.add(menuD);
		menus.add(barre);
		setJMenuBar(menus);
		
		
		button1.addActionListener(new BonnieListener());
		button2.addActionListener(new ClydeListener());
		button3.addActionListener(new CloseListener());
		
		buttonPanel.add(button1);
		buttonPanel.add(button2);
		buttonPanel.add(button3);
		add(buttonPanel, BorderLayout.SOUTH);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Telecommande");
		pack();
		setVisible(true);
	}
	
	class BonnieListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			text.append("Bonnie\n");		
		}
	}
	
	class ClydeListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			text.append("Clyde\n");		
		}
	}
	
	class CloseListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			System.exit(0);	
		}
	}
	
	class ActionBonnie extends AbstractAction {
		private static final long serialVersionUID = 1L;
		
		public ActionBonnie(String name) {
			super(name);
		}
		
		public void actionPerformed(ActionEvent e) {
			text.append("Bonnie\n");		
		}
		
	}
	
	class ActionClyde extends AbstractAction {
		private static final long serialVersionUID = 1L;
		
		public ActionClyde(String name) {
			super(name);
		}
		
		public void actionPerformed(ActionEvent e) {
			text.append("Clyde\n");		
		}
	}
	
	class ActionClose extends AbstractAction {
		private static final long serialVersionUID = 1L;
		
		public ActionClose(String name) {
			super(name);
		}
		
		public void actionPerformed(ActionEvent e) {
			System.exit(0);	
		}
	}

}

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

public class FrameMain extends JFrame {
    FrameMain ( ) {
        this.setLayout (null);

        JButton btnNewForm = new JButton ("NEW FORM");
        btnNewForm.setBounds (50, 50, 200, 100);
        this.add (btnNewForm);
        btnNewForm.addActionListener (new ActionListener () {
            @Override
            public void actionPerformed (ActionEvent e) {
                FrameForm form = new FrameForm (null);
            }
        });

        JButton btnDisplayForms = new JButton ("DISPLAY FORMS");
        btnDisplayForms.setBounds (300, 50, 200, 100);
        this.add (btnDisplayForms);
        btnDisplayForms.addActionListener (new ActionListener () {
            @Override
            public void actionPerformed (ActionEvent e) {
                for (Person x : Main.list) {
                    FrameForm f = new FrameForm (x);
                }
            }
        });

        JButton btnSaveToDisk = new JButton ("SAVE TO DISK");
        btnSaveToDisk.setBounds (50, 200, 200, 100);
        this.add (btnSaveToDisk);
        btnSaveToDisk.addActionListener (new ActionListener () {
            @Override
            public void actionPerformed (ActionEvent e) {
                FileOutputStream fos = null;
                ObjectOutputStream out = null;
                try {
                    fos = new FileOutputStream ("save.dat");
                    out = new ObjectOutputStream (fos);
                    for (Person x : Main.list) {
                        out.writeObject (x);
                    }
                    out.close ();
                    JOptionPane.showMessageDialog (new JFrame (), "Saved to disk!", "Message", JOptionPane.INFORMATION_MESSAGE);
                } catch (Exception ex) {
                    ex.printStackTrace ();
                }

            }
        });

        JButton btnRestoreFromDisk = new JButton ("RESTORE FROM DISK");
        btnRestoreFromDisk.setBounds (300, 200, 200, 100);
        this.add (btnRestoreFromDisk);
        btnRestoreFromDisk.addActionListener (new ActionListener () {
            @Override
            public void actionPerformed (ActionEvent e) {
                FileInputStream fos = null;
                ObjectInputStream in = null;
                try {
                    fos = new FileInputStream ("save.dat");
                    in = new ObjectInputStream (fos);
                    while (true) Main.list.add ((Person) in.readObject ());
                } catch (EOFException ex) {
                    JOptionPane.showMessageDialog (new JFrame (), "Restored from disk!", "Message", JOptionPane.INFORMATION_MESSAGE);
                } catch (Exception ex) {
                    ex.printStackTrace ();
                }
            }
        });

        this.setBounds (150, 150, 600, 400);
        this.setVisible (true);
    }
}

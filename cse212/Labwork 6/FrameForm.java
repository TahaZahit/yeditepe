import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FrameForm extends JFrame {

    FrameForm (Person p) {
        this.setLayout (null);

        final JTextField txtName = new JTextField ();
        txtName.setBounds (150, 50, 150, 30);
        this.add (txtName);

        final JTextField txtSurname = new JTextField ();
        txtSurname.setBounds (150, 100, 150, 30);
        this.add (txtSurname);

        final JRadioButton rdSingle = new JRadioButton ("Single", true);
        final JRadioButton rdMarried = new JRadioButton ("Married", false);
        final JRadioButton rdDivorced = new JRadioButton ("Divorced", false);
        ButtonGroup maritalStatus = new ButtonGroup ();
        maritalStatus.add (rdSingle);
        maritalStatus.add (rdMarried);
        maritalStatus.add (rdDivorced);
        rdSingle.setBounds (100, 150, 100, 30);
        rdMarried.setBounds (200, 150, 100, 30);
        rdDivorced.setBounds (300, 150, 100, 30);
        this.add (rdSingle);
        this.add (rdMarried);
        this.add (rdDivorced);

        final JCheckBox chkBook = new JCheckBox ("Book");
        final JCheckBox chkSports = new JCheckBox ("Sports");
        final JCheckBox chkCinema = new JCheckBox ("Cinema");
        final JCheckBox chkArts = new JCheckBox ("Arts");
        chkBook.setBounds (50, 200, 100, 30);
        chkSports.setBounds (150, 200, 100, 30);
        chkCinema.setBounds (250, 200, 100, 30);
        chkArts.setBounds (350, 200, 100, 30);

        this.add (chkBook);
        this.add (chkSports);
        this.add (chkCinema);
        this.add (chkArts);

        if (p != null) {
            txtName.setText (p.name);
            txtSurname.setText (p.surname);
            rdSingle.setSelected (p.meritalStatus[0]);
            rdMarried.setSelected (p.meritalStatus[1]);
            rdDivorced.setSelected (p.meritalStatus[2]);
            chkBook.setSelected (p.interest[0]);
            chkSports.setSelected (p.interest[1]);
            chkCinema.setSelected (p.interest[2]);
            chkArts.setSelected (p.interest[3]);
        } else {
            JButton btnSave = new JButton ("SAVE");
            btnSave.setBounds (50, 250, 150, 30);
            this.add (btnSave);

            btnSave.addActionListener (new ActionListener () {
                @Override
                public void actionPerformed (ActionEvent e) {

                    boolean[] merital = new boolean[3];
                    merital[0] = rdSingle.isSelected ();
                    merital[1] = rdMarried.isSelected ();
                    merital[2] = rdDivorced.isSelected ();

                    boolean[] interest = new boolean[4];
                    interest[0] = chkBook.isSelected ();
                    interest[1] = chkSports.isSelected ();
                    interest[2] = chkCinema.isSelected ();
                    interest[3] = chkArts.isSelected ();

                    Person x = new Person (txtName.getText (), txtSurname.getText (), merital, interest);
                    Main.list.add (x);
                    dispose ();

                }
            });

            JButton btnClose = new JButton ("CLOSE");
            btnClose.setBounds (250, 250, 150, 30);
            this.add (btnClose);
            btnClose.addActionListener (e -> this.dispose ());

        }

        this.setBounds (250, 250, 480, 350);
        this.setVisible (true);
    }
}

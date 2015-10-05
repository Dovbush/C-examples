using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace WindowsFormsApplication1
{
    public partial class PhoneBook : Form
    {
        SqlConnection connection = new SqlConnection(@"data source = dev-pc\DEV;database = PhoneBookNew; 
                    integrated security = SSPI;");
       

        public PhoneBook()
        {
            InitializeComponent();
        }

        private void PhoneBook_Load(object sender, EventArgs e)
        {
            Display();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Clear();
            textBox3.Text = "";
            textBox4.Clear();
            comboBox1.SelectedIndex = -1;
            textBox1.Focus();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                connection.Open();
                SqlCommand cmd = new SqlCommand(@"INSERT INTO Mobile
                         (Name, Surname, Mobile, Email, [Group])
                            VALUES (' " + textBox1.Text + " ',' " + textBox2.Text + " ',' " + textBox3.Text + " ',' " + textBox4.Text + " ',' " + comboBox1.Text + " ')", connection);

                MessageBox.Show("Entry saved!");
                cmd.ExecuteNonQuery();
                connection.Close();
                Display();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        void Display()
        {
            SqlDataAdapter dataAdapter = new SqlDataAdapter("Select * from Mobile", connection);
            DataTable dataTable = new DataTable();
            dataAdapter.Fill(dataTable);
            dataGridView1.Rows.Clear();
            foreach (DataRow item in dataTable.Rows)
            {
                int newLine = dataGridView1.Rows.Add();
                dataGridView1.Rows[newLine].Cells[0].Value = item[0].ToString();
                dataGridView1.Rows[newLine].Cells[1].Value = item[1].ToString();
                dataGridView1.Rows[newLine].Cells[2].Value = item[2].ToString();
                dataGridView1.Rows[newLine].Cells[3].Value = item[3].ToString();
                dataGridView1.Rows[newLine].Cells[4].Value = item[4].ToString();
            }
        }

        private void dataGridView1_MouseClick(object sender, MouseEventArgs e)
        {
            string textline1 = dataGridView1.SelectedRows[0].Cells[0].Value.ToString();
            textBox1.Text = textline1.Replace(" ", "");
            string textline2 = dataGridView1.SelectedRows[0].Cells[1].Value.ToString();
            textBox2.Text = textline2.Replace(" ", "");
            string textline3 = dataGridView1.SelectedRows[0].Cells[2].Value.ToString();
            textBox3.Text = textline3.Replace(" ", "");
            string textline4 = dataGridView1.SelectedRows[0].Cells[3].Value.ToString();
            textBox4.Text = textline4.Replace(" ", "");
            comboBox1.Text = dataGridView1.SelectedRows[0].Cells[4].Value.ToString();

        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                connection.Open();
                SqlCommand cmd = new SqlCommand(@"DELETE FROM Mobile
                WHERE (Surname = ' " + textBox2.Text + " ')", connection);
                
                cmd.ExecuteNonQuery();
                connection.Close();
                MessageBox.Show("Entry deleted!");
                //delete from fields
                textBox1.Text = "";
                textBox2.Clear();
                textBox3.Text = "";
                textBox4.Clear();
                comboBox1.SelectedIndex = -1;
                textBox1.Focus();
                //show all entries
                Display();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        
    }
}   

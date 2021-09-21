# Κατασκευή Ρομποτικού Ηλιοτρόπιου

### Έργο & Ομάδα

Στη διάρκεια του σχολικού έτους 2020-2021 η ομάδα ρομποτικής **@robot7gymchai** του σχολείου μας, αποτελείται από τους μαθητές της τρίτης τάξης Βατόγλου Χρήστο, Δέδε Τάσο και τον καθηγητή πληροφορικής Μαχαιρίδη Τάσο.

### Στόχος (Το πρόβλημα)

Στόχος της ομάδας ρομποτικής του σχολείου μας είναι η κατασκευή ενός **ηλιοτρόπιου**, δηλαδή ενός ρομποτικού μηχανισμού που τρέπεται προς τον ήλιο (solar tracker) και θα εκμεταλλεύεται με τον καλύτερο τρόπο, την ισχυρότερη ανανεώσιμη πηγή ενέργειας στη γης, το ηλιακό φως.
Ο ρομποτικός μηχανισμός θα είναι ένας αρθρωτός βραχίονας που στηρίζει ένα συλλέκτη ηλιακής ενέργειας στην κορυφή του. Ο βραχίονας θα είναι δύο βαθμών ελευθερίας, ώστε να μπορεί να στρέφεται γύρω από τον οριζόντια άξονα του συλλέκτη και γύρω από τον κάθετο άξονα της βάσης του.
Θα ανιχνεύει συνεχώς μια πηγή φωτός, συγκεκριμένα τον ήλιο, χρησιμοποιώντας αισθητήρες φωτός, αναλογικούς, ή ψηφιακούς.
Ο συλλέκτης θα είναι μια φωτοβολταϊκή κυψέλη που θα μετατρέπει τη φωτεινή ενέργεια σε ηλεκτρική και θα την αποθηκεύει σε επαναφορτιζόμενες μπαταρίες, από τις οποίες ίσως να τροφοδοτείται όλο το σύστημα.
Ο έλεγχος των κινητήρων και των φωτοαισθητήρων θα γίνεται με μικροελεγκτή, μέσω λογισμικού. Το πρόγραμμα θα στρίβει τον συλλέκτη στην κατεύθυνση με τη μέγιστη απόδοση απορρόφησης ενέργειας. 

### Υλικά

Για την υλοποίηση του έργου, χρειάστηκαν:
  - Αρχικά για το πρότυπο, ένα μέρος από υπάρχον κιτ ρομποτικού βραχίονα με έξι βαθμούς ελευθερίας, περιορισμένο στους δύο βαθμούς ελευθερίας. Και στο τελικό προϊόν, ρομποτική ιδιοκατασκευή με στρεφόμενο πλαίσιο (Pan/Tilt), αποτελούμενη από πλαστική βάση από θήκη DVD, στηρίγματα από σκληρό χαρτόνι, μεταλλικό άξονα και δύο σερβοκινητήρες, ροπής 5 κιλών ο καθένας με πλήμνες σύνδεσης (hubs).
  - Τέσσερις αισθητήρες φωτός, αρχικά αναλογικούς, δηλαδή φωτοαντιστάσεις (light dependent resistor, LDR 5mm) και στο τελικό στάδιο ψηφιακούς σε μορφή μικρής πλακέτας (Digital Light Sensor Module, BH1750FVI).
  - Φωτοβολταϊκή Κυψέλη ισχύος 3,5 βατ, μέσης τάσης 6 βολτ, που αποδίδει ρεύμα έως 600 μιλιαμπέρ, χαμηλού βάρους μέχρι 100 γραμμάρια.
  - Επαναφορτιζόμενη πλακέ μπαταρία Ιόντων-Λιθίου (Li-Ion), χωρητικότητας 3.500 μιλι-αμπερωρίων στα 3,7 βολτ, που αποδίδει ισχύ μέχρι 13 βατ-ώρες.
  - Ρυθμιστής Φόρτισης της μπαταρίας (Solar Lithium Battery Charger, CN3065) με έξοδο για φορτίο και είσοδο USB για επιπλέον φόρτιση.
  - πλακέτα με θύρα σύνδεσης USB
  - Μικροελεγκτή Arduino Uno.
  - Εξωτερικό τροφοδοτικού στα 5 βολτ και πάνω από 2 αμπέρ.
  - Διάφορα καλώδια σύνδεσης, πλακέτα breadboard, θερμοσυστελλόμενα, χοντρό χαρτόνι ,κλπ.
Εργαλεία: πριόνι ξύλου, ψαλίδι, πιστόλι θερμόκολλας, λεπίδι, κατσαβίδια, πολύμετρο, χάρακας

### Υλοποίηση – Κατασκευή προτύπου

Σε πρώτη φάση, χρησιμοποιήσαμε σαν πρότυπο έναν ρομποτικό βραχίονα που είχαμε συναρμολογήσει σε παλιότερο έργο. Αφαιρέσαμε τέσσερις από τους έξι βαθμούς ελευθερίας, δηλ. αρθρώσεις και κινητήρες, ώστε το ρομπότ να μείνει μόνο με τη δυνατότητα περιστροφής όλου του συστήματος και τη δυνατότητα ανύψωσης μιας άρθρωσης.

![Img 0642-1_Moment](https://user-images.githubusercontent.com/38431707/134203574-1de3cf24-bb77-45be-96a6-e96de2057086.jpg)

Πάνω στην άρθρωση κολλήσαμε ένα μακετόχαρτο με την ηλιακή κυψέλη και πίσω της έναν μικροελεγκτή Uno με την αντίστοιχη πλακέτα προτυποποίησης (Breadboard) με βάση. Γύρω από την κυψέλη, σε 4 σημεία, (πάνω, κάτω, δεξιά, αριστερά) τρυπήσαμε το μακετόχαρτο και τοποθετήσαμε 4 αισθητήρες. Δηλαδή, φωτοαντιστάσεις LDR, μαζί με μικρά χαρτονάκια δίπλα τους σαν σκίαστρα. Η κάθε μια φωτοαντίσταση τροφοδοτήθηκε με παροχή τάσης 5v (και φυσικά γειώθηκε) και το άλλο άκρο συνδέθηκε σε σειρά, μέσω μιας αντίστασης 100kΩ, σε 4 αναλογικούς ακροδέκτες του ελεγκτή.

<img src="https://user-images.githubusercontent.com/38431707/134204531-feaf221e-eab8-4f17-a181-3873644b52ac.jpg" width="400" /> <img src="https://user-images.githubusercontent.com/38431707/134204546-57482aed-41ca-4252-9d7d-6ddc58dc8275.jpg" width="400" />

Επιπλέον, συνδέσαμε την έξοδο της κυψέλης σε μια πλακέτα ρυθμιστή φόρτισης, που με τη σειρά της παρέχει ρεύμα σε μια επαναφορτιζόμενη μπαταρία λιθίου. Παράλληλα συνδεμένη με την μπαταρία, είναι μια μικρή πλακέτα με θύρα σύνδεσης USB για τη φόρτιση συσκευών, όπως π.χ. κινητό τηλέφωνο.

https://user-images.githubusercontent.com/38431707/132997516-3ed94720-28ed-436f-aa81-51ad9942730a.mp4

### Κώδικας – Εργαλεία – Γλώσσα

Ο προγραμματισμός του μικροελεγκτή γίνεται στο περιβάλλον “Arduino Web Editor” στον ιστότοπο της εταιρείας. Μέσα από το chrome, αφού συνδεθούμε με τον λογαριασμό μας, πληκτρολογούμε τον πηγαίο κώδικα, τον μεταφράζουμε και ανεβάζουμε το εκτελέσιμο αρχείο στον μικροελεγκτή, μέσω της σειριακής του θύρας και της USB του υπολογιστή. Η γλώσσα προγραμματισμού είναι μια παραλλαγή της C++11.

Στον κεντρικό βρόχο του προγράμματος, διαβάζουμε, στις αναλογικές θύρες, με τη σειρά, την τάση στα ζεύγη των φωτοαντιστάσεων, δηλαδή, δεξί-αριστερό και πάνω-κάτω και υπολογίζουμε την διαφορά ανάμεσα στις τιμές του κάθε ζεύγους. Στην περίπτωση που η διαφορά ξεπερνάει την πρώτη τιμή του ζεύγους κατά ένα σταθερό ποσοστό (π.χ. 10%), τότε δίνουμε την εντολή να γυρίσει ο αντίστοιχος άξονας του ζεύγους προς την κατεύθυνση με τη μεγαλύτερη τιμή φωτός. Για το ζεύγος δεξί-αριστερό είναι ο άξονας της βάσης και για το ζεύγος πάνω-κάτω είναι ο άξονας της κλίσης.

Έτσι εξασφαλίζουμε πως το ρομποτικό θα στρέψει την πλάκα με την κυψέλη, προς την κατεύθυνση του πιο έντονου φωτός. Το σταθερό ποσοστό που αναφέραμε παραπάνω, φιλτράρει τις μικρές αλλαγές της φωτεινότητας, ώστε να εξαφανίσουμε το τρέμουλο (jitter) που αλλιώς παρουσιάζει το ρομπότ και έχει σαν αποτέλεσμα να ταλαιπωρούνται οι κινητήρες και τα γρανάζια του (και τα αυτιά μας).

Το πρότυπο δοκιμάστηκε και λειτούργησε πολύ καλά, όπως φαίνεται και το βίντεο, αλλά μας σκλάβωνε ένα ρομποτικό βραχίονα του εργαστηρίου πληροφορικής και οι φωτοαντιστάσεις δε λειτουργούσαν αξιόπιστα σε αλλαγές του φωτισμού του περιβάλλοντος χώρου. Αυτό είχε σαν αποτέλεσμα να χρειάζεται να επεμβαίνουμε στον κώδικά σε κάθε αλλαγή τοποθεσίας του ηλιοτρόπιου. Έτσι, περάσαμε στο επόμενο στάδιο που ήταν η…

### Κατασκευή του τελικού Ηλιοτρόπιου

Σε μια πλαστική βάση από θήκη DVD στερεώσαμε όρθιο έναν σερβοκινητήρα και επάνω στον άξονά του, βιδώσαμε μια περιστρεφόμενη ορθογώνια βάση από χοντρό χαρτόνι. Στο χαρτόνι αυτό, σταθεροποιήσαμε, με πλαστικά δεματικά στραπ, ένα ανάποδο «Π», πάλι από χοντρό χαρτόνι. Στα πλαϊνά του κάναμε δυο τρύπες με σουβλί και περάσαμε ένα μεταλλικό άξονα, με το ένα του άκρο συνδεμένο σε ένα δεύτερο σερβοκινητήρα, ο οποίος είναι στερεωμένος στο χαρτονένιο πλαϊνό.

<img src="https://user-images.githubusercontent.com/38431707/134203858-1cdad6bd-9474-4ab2-8724-30ee91c4e9af.jpg" height="400" /> <img src="https://user-images.githubusercontent.com/38431707/134203914-c128c22f-79ad-4cb6-b766-8c7488d65358.jpg" width="600" />

Στον άξονα προσαρμόζεται με σφιγκτήρες, κομμάτι κόντρα πλακέ που φέρει κολλημένη πάνω του την ηλιακή κυψέλη. Με αυτή την κατασκευή έχουμε ουσιαστικά την ίδια λειτουργία κίνησης με τον ρομποτικό βραχίονα. 

Γύρω από την κυψέλη, αντικαθιστούμε τις τέσσερις φωτοαντιστάσεις, με ψηφιακά φωτόμετρα σε μορφή μικρής πλακέτας, με δυνατότητα αξιόπιστης μέτρησης της απόλυτης τιμής του φωτός σε μονάδες lux. Αυτές οι πλακέτες συνδέθηκαν σε πλακέτα δοκιμών που κολλήθηκε στην πλάτη του κόντρα πλακέ.

<img src="https://user-images.githubusercontent.com/38431707/134202339-a60c911e-e7c3-4374-97ca-5e708461f065.jpg" height="400" /> <img src="https://user-images.githubusercontent.com/38431707/134205729-f0e4766d-ae07-4580-882c-37a7f50cd571.jpg" height="400" />  <img src="https://user-images.githubusercontent.com/38431707/134204272-53ef69a2-2d05-4363-8bea-d5d7bd984046.jpg" height="400" />

Για κάθε μια πλακέτα, οι συνδέσεις αφορούσαν την τροφοδοσία και τη γείωση και για τη μεταφορά των μετρήσεων τρεις συνδέσεις ακόμα. Δυο για τον δίαυλο δεδομένων I²C (ρολόι SCL και δεδομένα SDA) και μια για τη διεύθυνση πρόσβασης ADDR.

<img src="https://user-images.githubusercontent.com/38431707/134204136-6591a03b-3162-4849-a4c5-09f412b448c0.jpg" width="400" /> <img src="https://user-images.githubusercontent.com/38431707/134204331-01bbaa01-57b1-49ad-b34f-9bdfed34dd52.jpg" width="400" />

Η ενδιάμεση πλακέτα δοκιμών τροφοδοτείται από τον ελεγκτή μέσω καλωδίων, ενώ οι κινητήρες έχουν ανεξάρτητες γραμμές τροφοδοσίας μεγαλύτερων απαιτήσεων σε ισχύ, που ικανοποιούνται με εξωτερικό τροφοδοτικό. 

<img src="https://user-images.githubusercontent.com/38431707/134204149-70c6f40e-11fb-4968-940c-a6977bdda112.jpg" width="600" /> <img src="https://user-images.githubusercontent.com/38431707/134204371-6bf94281-282d-4d4d-96c2-e7f781a6a213.jpg" height="400" />

Μέσω της ίδιας ενδιάμεσης πλακέτας και οι συνδέσεις διαύλου δεδομένων καταλήγουν στους αντίστοιχους ακροδέκτες SCL και SDA του ελεγκτή. Αντίθετα, οι 4 συνδέσεις διευθύνσεων καταλήγουν στους ψηφιακούς ακροδέκτες του ελεγκτή D10, D11, D12, D13. Με αυτόν το τρόπο μπορεί να αλλάζει δυναμικά, η τυπική διεύθυνση επικοινωνίας μιας πλακέτας φωτόμετρου, ανεβάζοντας την τάση του ακροδέκτη διεύθυνσης από χαμηλή (LOW) σε ψηλή (HIGH).

Ο κώδικας φυσικά προσαρμόζεται στους ψηφιακούς αισθητήρες, αλλά ή λογική του παραμένει βασικά ή ίδια.

### Δοκιμές – Μετρήσεις

Το τελικό Ηλιοτρόπιο δοκιμάστηκε και ικανοποίησε απόλυτα το σκοπό της εργασίας μας, όπως φαίνεται και το βίντεο, οπότε κρίθηκε πετυχημένο.
Και οι δυο κατασκευές μπορούν να ακολουθήσουν με ακρίβεια την πορεία του ήλιου ή οποιασδήποτε άλλης πηγής φωτός και μάλιστα με αρκετή ταχύτητα και σταθερά, χωρίς ενοχλητικό τρέμουλο. Η μπαταρία επαναφορτίζεται κανονικά και μπορεί να αποδώσει την αποθηκευμένη ενέργειά της φορτίζοντας το κινητό μας η κάποια άλλη συσκευή.

### Επέκταση

Μια καλή επέκταση του έργου θα ήταν η ενεργειακή αυτονομία των κινητήρων, χρησιμοποιώντας την μπαταρία λιθίου αντί για εξωτερική τροφοδοσία.


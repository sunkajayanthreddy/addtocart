Action()
{
	web_set_max_html_param_len("9999");
	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-IN,en;q=0.9");

	lr_start_transaction("JpetStore_SC01_TC01_Launch");
	
	web_reg_save_param("C_jsessionid","lb=jsessionid=","rb=\"",LAST);
	web_reg_save_param("C__sourcePage","lb=_sourcePage\" value=\"","rb=\"",LAST);
	web_reg_save_param("C___fp","lb=__fp\" value=\"","rb=\"",LAST);
	web_reg_find("Text=Sign In","savecount=Launchpage",LAST);
	web_url("Catalog.action",
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	if(atoi(lr_eval_string("{Launchpage}"))>0)
			
	{
		lr_output_message("Valid Response");
		lr_end_transaction("JpetStore_SC01_TC01_Launch",LR_PASS);
	}
		else
    {  
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC01_TC01_Launch",LR_AUTO);
       lr_abort();
	}
	
	lr_think_time(2);

	lr_start_transaction("JpetStore_SC01_TC02_Signin");
	
    web_reg_find("text=Please enter your username and password","savecount=Signin",LAST);
    
	web_url("Sign In", 
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid={C_jsessionid}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	if(atoi(lr_eval_string("{Signin}"))>0)
			
	{
		lr_output_message("Valid Response");
		lr_end_transaction("JpetStore_SC01_TC02_Signin",LR_PASS);
	}
		else
    {  
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC01_TC02_Signin",LR_AUTO);
       lr_abort();
	}

	lr_think_time(2);

	lr_start_transaction("JpetStore_SC01_TC03_Login");
	
     web_reg_find("text=Freshwater","savecount=Login",LAST);

    web_reg_save_param("C_categoryId","lb=categoryId=","rb=\"",LAST);
	web_submit_data("Account.action", 
		"Action=https://petstore.octoperf.com/actions/Account.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action;jsessionid={C_jsessionid}", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={P_username}", ENDITEM, 
		"Name=password", "Value={P_pwd}", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value={C__sourcePage}", ENDITEM, 
		"Name=__fp", "Value={C___fp}", ENDITEM, 
		LAST);

	if(atoi(lr_eval_string("{Login}"))>0)
			
	{
		lr_output_message("Valid Response");
		lr_end_transaction("JpetStore_SC01_TC03_Login",LR_PASS);
	}
		else
    {  
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC01_TC03_Login",LR_AUTO);
       lr_abort();
	}

	lr_think_time(2);

	lr_start_transaction("JpetStore_SC01_TC04_Click_On_Fish");

	web_reg_save_param("C_productId","lb=productId=","rb=\"",LAST);
	
	web_reg_find("text=Fish","savecount=fish",LAST);
	 
	web_url("sm_fish.gif",
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId={C_categoryId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	if(atoi(lr_eval_string("{fish}"))>0)
			
	{
		lr_output_message("Valid Response");
		lr_end_transaction("JpetStore_SC01_TC04_Click_On_Fish",LR_PASS);
	}
		else
    {  
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC01_TC04_Click_On_Fish",LR_AUTO);
       lr_abort();
	}

	lr_think_time(2);

	lr_start_transaction("JpetStore_SC01_TC05_Click_On_Product_ID");
    
	web_reg_save_param("C_itemid","lb=itemId=","rb=\"",LAST);
	
	web_reg_find("text=Description","savecount=Product_ID",LAST);
	
	web_url("FI-SW-02",
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId={C_productId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId={C_categoryId}", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	if(atoi(lr_eval_string("{Product_ID}"))>0)
			
	{
		lr_output_message("Valid Response");
		lr_end_transaction("JpetStore_SC01_TC05_Click_On_Product_ID",LR_PASS);
	}
		else
    {  
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC01_TC05_Click_On_Product_ID",LR_AUTO);
       lr_abort();
	}

	lr_think_time(3);

	lr_start_transaction("JpetStore_SC01_TC06_Click_On_EST-3");
	web_reg_find("Text=Salt Water fish from Australia","savecount=EST",LAST);
	web_url("EST-3", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewItem=&itemId={C_itemid}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId={C_productId}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	if(atoi(lr_eval_string("{EST}"))>0)		
	{
		lr_output_message("Valid Response");
        lr_end_transaction("JpetStore_SC01_TC06_Click_On_EST-3",LR_PASS);
	}
		else
    {  
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC01_TC06_Click_On_EST-3",LR_AUTO);
       lr_abort();
	}
	
	lr_think_time(4);

	lr_start_transaction("JpetStore_SC01_TC07_cloick_On_Add_To_Cart");
	web_reg_save_param("C__sourcePage2","lb=_sourcePage\" value=\"","rb=\"",LAST);
	web_reg_save_param("C__fp2","lb=_fp\" value=\"","rb=\"",LAST);
	web_reg_find("Text=Shopping Cart","savecount=addto cart page",LAST);
	web_url("Add to Cart", 
		"URL=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId={C_itemid}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewItem=&itemId={C_itemid}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	if(atoi(lr_eval_string("{addto cart page}"))>0)
			
	{
		lr_output_message("Valid Response");
        lr_end_transaction("JpetStore_SC01_TC07_cloick_On_Add_To_Cart",LR_PASS);
	}
		else
    {  
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC01_TC07_cloick_On_Add_To_Cart",LR_AUTO);
       lr_abort();
	}

	lr_think_time(4);

	lr_start_transaction("JpetStore_SC01_TC08_Click_On_Product_To_Checkout");
	web_reg_find("Text=Payment Details","savecount=product checkout page",LAST);
	web_url("Proceed to Checkout", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId={C_itemid}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	if(atoi(lr_eval_string("{product checkout page}"))>0)		
	{
		lr_output_message("Valid Response");
       lr_end_transaction("JpetStore_SC01_TC08_Click_On_Product_To_Checkout",LR_PASS);
	}
		else
    {  
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC01_TC08_Click_On_Product_To_Checkout",LR_AUTO);
       lr_abort();
	}
	
	lr_think_time(3);

	lr_start_transaction("JpetStore_SC01_TC09_Click_On_Continue");
	web_reg_find("Text=Billing Address","savecount=clickon continue page",LAST);
	web_submit_data("Order.action", 
		"Action=https://petstore.octoperf.com/actions/Order.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=order.cardType", "Value=Visa", ENDITEM, 
		"Name=order.creditCard", "Value=999 9999 9999 9999", ENDITEM, 
		"Name=order.expiryDate", "Value=12/03", ENDITEM, 
		"Name=order.billToFirstName", "Value=ABC", ENDITEM, 
		"Name=order.billToLastName", "Value=XYX", ENDITEM, 
		"Name=order.billAddress1", "Value=901 San Antonio Road", ENDITEM, 
		"Name=order.billAddress2", "Value=MS UCUP02-206", ENDITEM, 
		"Name=order.billCity", "Value=Palo Alto", ENDITEM, 
		"Name=order.billState", "Value=CA", ENDITEM, 
		"Name=order.billZip", "Value=94303", ENDITEM, 
		"Name=order.billCountry", "Value=USA", ENDITEM, 
		"Name=newOrder", "Value=Continue", ENDITEM, 
		"Name=_sourcePage", "Value={C__sourcePage2}", ENDITEM, 
		"Name=__fp", "Value={C__fp2}", ENDITEM, 
		LAST);
	if(atoi(lr_eval_string("{clickon continue page}"))>0)		
	{
		lr_output_message("Valid Response");
        lr_end_transaction("JpetStore_SC01_TC09_Click_On_Continue",LR_PASS);
	}
		else
    {  
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC01_TC09_Click_On_Continue",LR_AUTO);
       lr_abort();
	}

	lr_think_time(2);

	lr_start_transaction("JpetStore_SC01_TC10_Click_On_Confirm");
	web_reg_find("Text=your order has been submitted","savecount=confirm page",LAST);
	web_url("Confirm", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	if(atoi(lr_eval_string("{confirm page}"))>0)		
	{
		lr_output_message("Valid Response");
        lr_end_transaction("JpetStore_SC01_TC10_Click_On_Confirm",LR_PASS);
	}
		else
    {  
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC01_TC10_Click_On_Confirm",LR_AUTO);
       lr_abort();
	}
	
	lr_think_time(2);

	lr_start_transaction("JpetStore_SC01_TC11_Click_On_Sign_Out");
	web_reg_find("Text=Elevate you load-testing","savecount=signout page",LAST);
	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
	if(atoi(lr_eval_string("{signout page}"))>0)		
	{
		lr_output_message("Valid Response");
        lr_end_transaction("JpetStore_SC01_TC11_Click_On_Sign_Out",LR_PASS);
	}
		else
    {  
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC01_TC11_Click_On_Sign_Out",LR_AUTO);
       lr_abort();
	}
	

	return 0;
}